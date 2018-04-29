//
// Created by tgifr on 10.04.17.
//

#ifndef UDP_UDPCLIENTCLASS_H
#define UDP_UDPCLIENTCLASS_H

#include <progbase/net.h>
#include "NetMessageClass.h"
#include "IpAddressClass.h"

class UdpClientClass {
private:
    UdpClient client;
public:
    UdpClientClass();
    UdpClientClass( int port);
    bool Bind( IpAddressClass & address);
    void Close();
    bool ReceiveFrom(NetMessageClass & message, IpAddressClass & address);
    bool SendTo(NetMessageClass &message, IpAddressClass &address);
    IpAddressClass GetAddress();

};


#endif //UDP_UDPCLIENTCLASS_H
