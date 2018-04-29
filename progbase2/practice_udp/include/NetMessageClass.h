//
// Created by tgifr on 10.04.17.
//

#ifndef UDP_NETMESSAGECLASS_H
#define UDP_NETMESSAGECLASS_H

#include <progbase/net.h>

#include <string>

class NetMessageClass {
private:
    NetMessage netMessage;
public:
    NetMessageClass(char *buf, size_t bufLen);
    void SetData(const char * str, size_t bufLen);
    void SetData(const char * str);
    void SetData(std::string str);
    const char * GetData();
    int DataLength();
    NetMessage * GetNetMessage();

};


#endif //UDP_NETMESSAGECLASS_H
