//
// Created by tgifr on 10.04.17.
//

#ifndef UDP_IPADDRESS_H
#define UDP_IPADDRESS_H


#include <progbase/net.h>
class IpAddressClass {
private:
    struct IpAddress  ipAdress;
public:
    IpAddressClass(const char *ipv4, int port);
    IpAddressClass(int port);
    IpAddressClass(IpAddress toCopy);
    IpAddressClass();
    const char * GetAddress();
    int GetPort();
    IpAddress * GetIpAdress();
};


#endif //UDP_IPADDRESS_H
