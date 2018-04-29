//
// Created by tgifr on 11.04.17.
//

#include "../include/TcpListenerClass.h"

TcpListenerClass::TcpListenerClass() {
    TcpListener_init(&listener);
}

bool TcpListenerClass::Bind(IpAddressClass &address) {
    return TcpListener_bind(&listener, address.GetIpAdress());
}

bool TcpListenerClass::Start() {
    return TcpListener_start(&listener);
}

void TcpListenerClass::Close() {
    TcpListener_close(&listener);
}

TcpClientClass TcpListenerClass::Accept(TcpClientClass &client) {
    return TcpClientClass(*TcpListener_accept(&listener, client.GetTcpClient()));
}

IpAddressClass TcpListenerClass::Address() {
    return IpAddressClass(*TcpListener_address(&listener));
}
