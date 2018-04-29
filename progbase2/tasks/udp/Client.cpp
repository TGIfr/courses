//
// Created by tgifr on 11.04.17.
//
#include <stdio.h>
#include <iostream>
#include "include/UdpClientClass.h"


#define BUFFER_LEN 1024

int main(void) {
    //
    // create UDP client
    UdpClientClass * client = new  UdpClientClass();
    IpAddressClass * serverAddress = new IpAddressClass( "127.0.0.1", 9998);
    char buf [BUFFER_LEN];
    NetMessageClass * message = new NetMessageClass(
            //! IMPORTANT some more c++ pure magic comes below

            buf, // it just don`t work in c++( char[BUFFER_LEN]){},  // array on stack
            BUFFER_LEN);

    while (1) {
        std::cout << "Please, input request:\n";
        std::string str;
        std::getline(std::cin,str);
        message->SetData(str);
        // send request to server
        client->SendTo( *message, *serverAddress);
        //
        // blocking call to receive response data from server
        client->ReceiveFrom( *message, *serverAddress);
        std::cout <<"Received message from server ("
                  << message->DataLength()
                  << " bytes): `"
                  << message->GetData()
                  << "`\n";

    }
    //
    // close client
    client->Close();
    return 0;
}

