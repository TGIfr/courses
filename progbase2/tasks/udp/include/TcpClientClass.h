//
// Created by tgifr on 11.04.17.
//

#ifndef UDP_TCPCLIENTCLASS_H
#define UDP_TCPCLIENTCLASS_H
#include <progbase/net.h>


#include "IpAddressClass.h"
#include "NetMessageClass.h"

class TcpClientClass {
private:
    TcpClient client;
public:
    TcpClientClass();
    TcpClientClass(TcpClient client);
    bool Connect(IpAddressClass & serverAddress);
    void Close();
    bool Receive(NetMessageClass & message);
    bool Send( NetMessageClass & message);
    IpAddressClass Address();
    TcpClient * GetTcpClient();

};


#endif //UDP_TCPCLIENTCLASS_H
