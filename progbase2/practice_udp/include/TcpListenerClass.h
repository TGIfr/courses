//
// Created by tgifr on 11.04.17.
//

#ifndef UDP_TCPLISTENERCLASS_H
#define UDP_TCPLISTENERCLASS_H

#include <progbase/net.h>

#include "IpAddressClass.h"
#include "TcpClientClass.h"

class TcpListenerClass {
private:
    TcpListener listener;
public:
    TcpListenerClass();
    bool Bind(IpAddressClass & address);
    bool Start();
    void Close();
    TcpClientClass  Accept( TcpClientClass & client);
    IpAddressClass  Address();
};


#endif //UDP_TCPLISTENERCLASS_H
