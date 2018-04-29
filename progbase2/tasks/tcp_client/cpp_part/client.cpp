//
// Created by tgifr on 20.04.17.
//



#include <iostream>
#include <progbase-cpp/net.h>

using namespace std;
using namespace progbase::net;

int main(){
    TcpClient client;
    NetMessage message(100);
    try {
        int port = 3002;
        string adressStr = "127.0.0.1";
        std::string totalReceivedStr = "";
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
        cout << totalReceivedStr;

    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}