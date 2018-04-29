//
// Created by tgifr on 11.04.17.
//

#include "../include/TcpClientClass.h"

TcpClientClass::TcpClientClass() {
    TcpClient_init(&client);
}

TcpClientClass::TcpClientClass(TcpClient client) {
    this->client = client;
}

bool TcpClientClass::Connect(IpAddressClass &serverAddress) {
    return TcpClient_connect(&client, serverAddress.GetIpAdress());
}

void TcpClientClass::Close() {
    TcpClient_close(&client);
}

bool TcpClientClass::Receive(NetMessageClass &message) {
    return TcpClient_receive(&client, message.GetNetMessage());
}

bool TcpClientClass::Send(NetMessageClass &message) {
    return TcpClient_send(&client, message.GetNetMessage());
}

IpAddressClass TcpClientClass::Address() {
    return IpAddressClass(this->client.address);
}

TcpClient *TcpClientClass::GetTcpClient() {
    return &client;
}
