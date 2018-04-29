//
// Created by tgifr on 10.04.17.
//

#include "../include/IpAddressClass.h"


IpAddressClass::IpAddressClass(const char *ipv4, int port){
    IpAddress_init(&ipAdress, ipv4, port);
}
IpAddressClass::IpAddressClass(int port){
    IpAddress_initAny(&ipAdress, port);
}
const char * IpAddressClass::GetAddress(){
    return IpAddress_address(&ipAdress);
}
int IpAddressClass::GetPort(){
    return IpAddress_port(&ipAdress);
}

IpAddress *IpAddressClass::GetIpAdress() {
    return &ipAdress;
}

IpAddressClass::IpAddressClass(IpAddress toCopy) {
    this->ipAdress = toCopy;
}

IpAddressClass::IpAddressClass() {
    //kinda empty
}
