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
enum RESULTS{
    ERR = -1,
    ADD,
    LENGTH,
    GET_ALL,
    GET_BY_INDEX,
    CHANGE
};
vector<std::string> getTokens(std::string str);
int analyzeTokens(vector<std::string> tokens);
std::string getRestOfStr(vector<std::string> tokens, int index);

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
    while (1) {
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
            case LENGTH:
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
            case CHANGE:
                firstToken = tokens.at(1);
                if(firstToken.at(0)) {
                    index = std::stoi(firstToken);
                    if (index < list.size() && index >= 0) {
                        list.at(index) = getRestOfStr(tokens, 2);
                        message->SetData("replaced successfully\n");
                        cout << "Replaced successfully \n";
                        break;
                    }
                }
                message->SetData("wrong index\n");
                cout << "Replaced unsuccessfully \n";
                break;
            case ERR:
                message->SetData("wrong command\n");
                cout << "Dunno what received\n";
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
        if(!first.compare("length") ) return LENGTH;
        if(!first.compare("getAll")) return GET_ALL;
        if(!first.compare("get") && size > 1) return GET_BY_INDEX;
        if(!first.compare("change") && size > 2) return CHANGE;
    }
    return ERR;
}

