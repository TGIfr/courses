//
// Created by tgifr on 10.04.17.
//

#include "../include/UdpClientClass.h"
//#include <progbase/net.h>

UdpClientClass::UdpClientClass() {
    UdpClient_init(&client);
}

// !!! no UdpClient_initBind in net.c
//UdpClientClass::UdpClientClass(int port) {
//    UdpClient_initBind(&client, port);
//}

bool UdpClientClass::Bind(IpAddressClass &address) {
    return UdpClient_bind(&client, address.GetIpAdress());
}

void UdpClientClass::Close() {
    UdpClient_close(&client);
}

bool UdpClientClass::ReceiveFrom(NetMessageClass &message, IpAddressClass &address) {
    return UdpClient_receiveFrom(&client, message.GetNetMessage(), address.GetIpAdress());
}

bool UdpClientClass::SendTo(NetMessageClass &message, IpAddressClass &address) {
    return UdpClient_sendTo(&client, message.GetNetMessage(), address.GetIpAdress());
}

IpAddressClass UdpClientClass::GetAddress() {
    return IpAddressClass(this->client.address);
}
