//
// Created by tgifr on 22.05.17.
//

#ifndef KR2_SENDER_H
#define KR2_SENDER_H

//! interface for server part and for user interface
#include "CustomDataType.h"
#include <progbase-cpp/net.h>

#include "json.hpp"

using namespace progbase::net;

typedef enum {
    PRINT,
    GET_STATE,
    ADD_SONG,
    START_BY_INDEX,
    PLAY_NEXT,
    PLAY_PREVIOUS,
    GET_PLAYED,
    LOUD_GET,
    LOUD_SET,
    PLAY_STOP,
    PLAY_PAUSE,
    DELETE_SONG
    //! FFTA
} Function;
enum Status {
    OK,
    FAILED,
};



typedef struct {
    Function function;
    CustomDataType data;
} FunctionCall;

typedef struct {
    Status res;
    CustomDataType data;
    Function function;
} FunctionCallResult;

class Sender {
private:
    TcpClient * client;
    bool isBound = false;
    NetMessage lastMessage{2000};
    std::string functionCallToJsonStr(FunctionCall data);
    FunctionCall functionCallFromJsonStr(std::string jsonStr);
    std::string functionCallResultToJsonStr(FunctionCallResult data);
    FunctionCallResult functionCallResultFromJsonStr(std::string jsonStr);

public:
    ~Sender();
    //for client
    FunctionCallResult AskServer(FunctionCall data);
    //for server
    FunctionCall ReceiveFromClient();
    bool SendToClient(FunctionCallResult);
};


#endif //KR2_SENDER_H
