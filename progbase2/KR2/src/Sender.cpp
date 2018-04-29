//
// Created by tgifr on 22.05.17.
//

#include "../include/Sender.h"
#include "../include/CustomDataType.h"

using nlohmann::json;
using namespace std;


std::string Sender::functionCallToJsonStr(FunctionCall data){
    //! FFTA
    json j;
    j["function"] = data.function;
    j["data/name"] = data.data.song.name;
    j["data/singer"] = data.data.song.singer;
    j["data/index"] = data.data.index;
    j["data/noiseLevel"] = data.data.noiseLevel;
    j["data/status"] = data.data.status;
    return j.dump();
}
FunctionCall Sender::functionCallFromJsonStr(std::string jsonStr){
    //! FFTA
    auto j = json::parse(jsonStr);
    FunctionCall res;
    string name = j["data/name"];
    string singer = j["data/singer"];
    int index = j["data/index"];
    PlayStatus status = j["data/status"];
    int noiseLevel = j["data/noiseLevel"];
    res.data = CustomDataType(name, singer, index, status, noiseLevel);
    res.function = j["function"];

    return res;
}
std::string Sender::functionCallResultToJsonStr(FunctionCallResult data){
    //! FFTA
    json j;
    j["function"] = data.function;
    j["data/singer"] = data.data.song.singer;
    j["data/index"] = data.data.index;
    j["data/noiseLevel"] = data.data.noiseLevel;
    j["data/status"] = data.data.status;
    j["status"] = data.res;
    j["data/name"] = data.data.song.name;
    return j.dump();
}
FunctionCallResult Sender::functionCallResultFromJsonStr(std::string jsonStr){
    //! FFTA
    auto j = json::parse(jsonStr);
    FunctionCallResult res;
    string name = j["data/name"];
    string singer = j["data/singer"];
    int index = j["data/index"];
    PlayStatus status = j["data/status"];
    int noiseLevel = j["data/noiseLevel"];
    res.data = CustomDataType(name, singer, index, status, noiseLevel);
    res.res = j["status"];
    res.function = j["function"];
    return res;
}

//for client
FunctionCallResult Sender::AskServer(FunctionCall data){
    TcpClient client;
    NetMessage message(100);
    string res = "";
    try {
        client.connect(IpAddress("127.0.0.1", 8080));
        message.setDataString(functionCallToJsonStr(data));
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            res  += message.dataAsString();
        } while (!message.isEmpty());
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return functionCallResultFromJsonStr(res);
}
//for server
FunctionCall Sender::ReceiveFromClient(){
    const int serverPort = 8080;
    TcpListener listener;
    try {
        if(!isBound) {
            listener.bind(IpAddress("127.0.0.1", serverPort));
            isBound = true;
        }
        listener.start();
        while (true) {
            cout << ">> Waiting for clients at " << serverPort << "..." << endl;
            client = listener.accept();
            client->receive(lastMessage);
            cout << ">> Received: " << endl << lastMessage.dataAsString() << endl;
            return  functionCallFromJsonStr(lastMessage.dataAsString());
        }
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
}
bool Sender::SendToClient(FunctionCallResult data){
    lastMessage.setDataString(functionCallResultToJsonStr(data));
    client->send(lastMessage);
    cout << ">> Response sent. \n" << lastMessage.dataAsString() << endl;
    delete client;
}

Sender::~Sender() {
    if(client != nullptr) {
        delete client;
    }
}
