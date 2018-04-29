#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;
bool isVowel(char c);

int main(){
    TcpClient client;
    NetMessage message(100);
    std::string totalReceivedStr = "";
    try {
        int port = 3002;
        string adressStr = "127.0.0.1";
        IpAddress address(adressStr, port);
        client.connect(address);
        message.setDataString("strings");
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            std::string str = message.dataAsString();
//            cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
            totalReceivedStr += str;
        } while (!message.isEmpty());
        cout <<"/nRECEIVED STR\n"<< totalReceivedStr;
        std::vector<string> result;
                QJsonDocument jdoc = QJsonDocument::fromJson(QString::fromStdString(totalReceivedStr).toUtf8());
                if (jdoc.isObject()) {
                    QJsonObject jobj = jdoc.object();
                    std::string status = jobj["status"].toString().toStdString();
                    if(status.compare("true")){
                        auto arr = jobj["data"].toArray();
                        for (auto item : arr) {
                            if (item.isString()) {
                                result.push_back(item.toString().toStdString());
                            }
                        }
                    } else
                        cout << "RECEIVED ERROR: " << jobj["error"].toString().toStdString() << endl;

                } else if (jdoc.isNull()) {
                    cout << "JSON is NULL" << endl;
                }
        cout << "\n\nVECTOR\n\n";
        for(auto item : result){
            cout << item << endl;
        }
        cout << "\n\nANALYZED VECTOR\n\n";
        for(int i = result.size() - 1; i >= 0; i --){
            if(!isVowel(result.at(i).at(0))){
                result.erase(result.begin() + i);
            }
        }
        for(auto item : result){
            cout << item << endl;
        }
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }



    return 0;
}
bool isVowel(char c) {
    switch(tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}
