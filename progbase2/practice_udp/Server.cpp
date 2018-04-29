#include <iostream>
#include "include/UdpClientClass.h"

#include <sstream>
#include <vector>
#include <iterator>

using namespace std;


#define BUFFER_LEN 1024
/*
 *  controls :
 *  add %string%
 *  length
 *  getAll
 *  get %index%
 *  change %index% %str%
 *
 */
/**
Сервер містить фіксований масив строк. При старті сервера строки у масиві порожні.
Клієнт може присилати запити серверу на зміну строки по певному індексу в масиві:
	* push <index> <char> - додати символ у кінець строки
	* pop <index> - забрати символ з кінця строки
	* clear <index> - очистити строку
	* get <index> - отримати строку за індексом
	* count - отримати кількість строк у масиві (розмір масиву)
	* getall - отримати масив всіх строк
У відповідь на правильні запити сервер відправляє клієнту строку або масив строк,
кожна строка у відповіді записується у окремому рядку
*/
enum RESULTS{
    ERR = -1,
    ADD,
    COUNT,
    GET_ALL,
    GET_BY_INDEX,
    CHANGE,
    PUSH,
    POP,
    CLEAR,
    EXIT
};
vector<std::string> getTokens(std::string str);
int analyzeTokens(vector<std::string> tokens);
std::string getRestOfStr(vector<std::string> tokens, int index);
bool getCorrectIndex(vector<std::string> list, std::string indexStr, int & index);

int main() {
    UdpClientClass * server =  new UdpClientClass();
    IpAddressClass * address = new IpAddressClass(9998);
    if (!server->Bind(*address) ) {
        perror("Can't start server");
        return 1;
    }
    cout << "Udp server started on port " << server->GetAddress().GetPort() << endl;
    char buf[BUFFER_LEN];
    NetMessageClass * message = new NetMessageClass(
            //! IMPORTANT some real c++ magic comes below
            buf, // it just don`t work in c++( char[BUFFER_LEN]){},  // array on stack
            BUFFER_LEN);

    IpAddressClass clientAddress;
    vector<std::string> list;
    std::string firstToken;
    int index;
    bool run = true;
    while (run) {
        puts("Waiting for data...");
        //
        // blocking call to receive data from clients
        server->ReceiveFrom( *message, clientAddress);
        cout << "Received message from "
                << clientAddress.GetAddress()<< ":"  // client IP-address
                << clientAddress.GetPort()<<  " (" // client port
                << message->DataLength() <<  "bytes): "
                << message->GetData() << endl;
        std::string data = message->GetData();
        auto tokens = getTokens(data);
        switch(analyzeTokens(tokens)){
            case ADD:
                list.push_back(getRestOfStr(tokens, 1));
                message->SetData("Successfully added\n");
                cout << "Successfully added\n";
                break;
            case COUNT:
                message->SetData(std::to_string(list.size()));
                cout << "Length sent\n";
                break;
            case GET_ALL:
                message->SetData(getRestOfStr(list, 0));
                cout << "All sent\n";
                break;
            case GET_BY_INDEX:
                firstToken = tokens.at(1);
                if(isdigit(firstToken.at(0))){
                    index = std::stoi(firstToken);
                    if(index < list.size() && index >=0){
                        message->SetData(list.at(index));
                        cout << "Sent successfully \n";
                     }
                }
                else {
                    message->SetData("wrong index\n");
                    cout << "Sent unsuccessfully \n";
                }
                break;
            case POP:
                firstToken = tokens.at(1);
                if(getCorrectIndex(list, firstToken, index)) {
                    if (list.at(index).length() > 1) {
                        list.at(index) = list.at(index).substr(0, list.at(index).size() - 1);
                        message->SetData("pop success");
                        cout << "Pop success \n";
                    } else {
                        message->SetData("Pop failed\n");
                        cout << "pop failed \n";
                    }
                }
                break;
            case CLEAR:
                firstToken = tokens.at(1);
                if(getCorrectIndex(list, firstToken, index)){
                    list.at(index) = "";
                    message->SetData("clear success");
                    cout << "Clear success \n";
                } else {
                    message->SetData("CLear failed\n");
                    cout << "Clear failed \n";
                }
                break;
            case CHANGE:
                firstToken = tokens.at(1);
                if(getCorrectIndex(list, firstToken, index)) {
                    list.at(index) = getRestOfStr(tokens, 2);
                    message->SetData("replaced successfully\n");
                    cout << "Replaced successfully \n";
                } else {
                    message->SetData("wrong index\n");
                    cout << "Replaced unsuccessfully \n";
                    }
                break;
            case PUSH:
                firstToken = tokens.at(1);
                if(getCorrectIndex(list, firstToken, index)) {
                    std::string rest = getRestOfStr(tokens, 2);
                    list.at(index) += rest.at(0);
                    message->SetData("pushed successfully\n");
                    cout << "Pushed successfully \n";
                } else {
                    message->SetData("wrong index\n");
                    cout << "Pushed unsuccessfully \n";
                    }
                break;
            case ERR:
                message->SetData("wrong command\n");
                cout << "Dunno what received\n";
                break;
            case EXIT:
                message->SetData("shutdown....\n");
                cout << "shutdown...\n";
                run = false;
                break;
        }

        // send echo response
        server->SendTo( *message, clientAddress);
    }
    //
    // close server
    server->Close();
    return 0;
}

std::string getRestOfStr(vector<std::string> tokens, int index){
    std::string result = "";
    for ( int i = index  ; i < tokens.size(); ++i) {
        result += tokens.at(i);
        result += " ";
    }
    return result;
}
vector<std::string> getTokens(std::string str){
    istringstream iss(str);
    vector<std::string> tokens{istream_iterator<std::string>{iss},
                               istream_iterator<std::string>{}};
    return tokens;
}
int analyzeTokens(vector<std::string> tokens){
    int size = tokens.size();
    if(size > 0){
        std::string first = tokens.at(0);
        if(!first.compare("add") && size > 1) return ADD;
        if(!first.compare("count") ) return COUNT;
        if(!first.compare("getAll")) return GET_ALL;
        if(!first.compare("get") && size > 1) return GET_BY_INDEX;
        if(!first.compare("change") && size > 2) return CHANGE;
        if(!first.compare("push") && size > 2) return PUSH;
        if(!first.compare("pop") && size > 1) return POP;
        if(!first.compare("clear") && size > 1) return CLEAR;
    }
    return ERR;
}
bool getCorrectIndex(vector<std::string> list, std::string indexStr, int & index){
    if(isdigit(indexStr.at(0))){
        index = std::stoi(indexStr);
        if(index < list.size() && index >=0){
            return true;
        }
    };
    return false;
}

