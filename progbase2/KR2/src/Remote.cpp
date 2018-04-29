//
// Created by tgifr on 22.05.17.
//

#include "../include/Remote.h"
#include "../include/Sender.h"



std::string Remote::PrintAndReturnWhatPrinted(CustomDataType toSend){
    Sender sender;
    FunctionCall data;
    data.data = toSend;
    data.function = PRINT;

    FunctionCallResult res = sender.AskServer(data);
    //!analyzing goes here

    return res.data.song.name;
}

void Remote::DeleteSong(int index){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType("blah", "blah", index);
    data.function = DELETE_SONG;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
void Remote::AddSong(Song song){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType(song, 0);
    data.function = ADD_SONG;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
void Remote::Pause(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = PLAY_PAUSE;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
void Remote::Stop(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = PLAY_STOP;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
void Remote::PlayNext(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = PLAY_NEXT;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
void Remote::PlayPrevious(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = PLAY_PREVIOUS;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
PlayStatus Remote::GetStatus(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = GET_STATE;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
    return res.data.status;
}
void Remote::Start(int index){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType("blah", "blah", index);
    data.function = Function::START_BY_INDEX;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}
Song Remote::GetPlayed(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = GET_PLAYED;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
    return res.data.song;
}
int Remote::GetLoud(){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType();
    data.function = LOUD_GET;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
    return res.data.noiseLevel;
}
void Remote::SetLoud(int loud){
    Sender sender;
    FunctionCall data;
    data.data = CustomDataType("blah", "blah", 0, PlayStatus::PLAYING, loud);
    data.function = LOUD_SET;

    FunctionCallResult res = sender.AskServer(data);
    std::cout << "Res " << res.res;
}