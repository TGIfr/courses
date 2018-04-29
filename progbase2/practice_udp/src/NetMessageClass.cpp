//
// Created by tgifr on 10.04.17.
//

#include "../include/NetMessageClass.h"

NetMessageClass::NetMessageClass(char *buf, size_t bufLen){
    NetMessage_init(&netMessage, buf, bufLen);
}
void NetMessageClass::SetData(const char * str, size_t bufLen){
    NetMessage_setData(&netMessage, str, bufLen);
}
void NetMessageClass::SetData(const char * str){
    NetMessage_setDataString(&netMessage, str);
}
const char * NetMessageClass::GetData(){
    return  NetMessage_data(&netMessage);
}
int NetMessageClass::DataLength(){
    return NetMessage_dataLength(&netMessage);
}

void NetMessageClass::SetData(std::string str){
    NetMessage_setDataString(&netMessage, str.c_str());
}

NetMessage *NetMessageClass::GetNetMessage() {
    return &netMessage;
}
