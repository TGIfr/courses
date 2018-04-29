#include <iostream>

#include "include/Sender.h"


const std::string INF_ABOUT_SERVER = "Аудіо-плеєр\n"
        "Отримати стан плеєра: ТрекНеОбрано, Зупинений, Відтворення, Пауза.\n"
        "Додати композицію у список\n"
        "Видалити композицію зі списку\n"
        "Розпочати відтворення композиції за індексом\n"
        "Відтворити наступний трек\n"
        "Відтворити попередній трек\n"
        "Отримати назву і виконавця поточної композиції (якщо обрана)\n"
        "Отримати рівень гучності\n"
        "Змінити рівень гучностi\n"
        "Зупинити відтворення\n"
        "Пауза відтворення";

const CustomDataType ERROR_TYPE("ERROR", "ERROR", 0, PlayStatus::TRACK_NOT_CHOSEN, 0);
int main() {
    Sender sender;
    CustomDataType currentSongData = ERROR_TYPE;
    std::vector<Song> playlist;
    while(true){
        FunctionCall call = sender.ReceiveFromClient();
        FunctionCallResult res;
        res.function = call.function;
        //! analyzing
        switch (call.function){
            case Function::PRINT :
                res.data = CustomDataType{INF_ABOUT_SERVER};
                res.res = Status::OK;
                break;

            case Function::ADD_SONG:
                playlist.push_back(call.data.song);
                res.res = Status :: OK;

                break;

            case Function::DELETE_SONG :
                if(call.data.index > 0 && call.data.index < playlist.size()){
                    playlist.erase(playlist.begin() + call.data.index);
                    res.res = Status::OK;
                } else{
                    res.res = Status::FAILED;
                }

                break;

            case Function::GET_PLAYED :
            case Function::GET_STATE :
            case Function::LOUD_GET:
                res.res = Status::OK;
                res.data = currentSongData;

                break;
            case Function::LOUD_SET :
                res.res = Status::OK;
                currentSongData.noiseLevel = call.data.noiseLevel;

                break;
            case Function::PLAY_STOP:
                if(currentSongData.status == PlayStatus::TRACK_NOT_CHOSEN){
                    res.res = Status::FAILED;
                } else{
                    currentSongData.status = PlayStatus ::STOP;
                    res.res = Status::OK;
                }

                break;
            case Function::PLAY_PAUSE :
                if(currentSongData.status == PlayStatus::TRACK_NOT_CHOSEN){
                    res.res = Status::FAILED;
                } else{
                    currentSongData.status = PlayStatus ::PAUSE;
                    res.res = Status::OK;
                }
                break;
            case Function::START_BY_INDEX :
                if(call.data.index < 0 || call.data.index > playlist.size()){
                    res.res = Status::FAILED;
                } else {
                    res.res = Status ::OK;
                    currentSongData = CustomDataType(playlist.at(call.data.index) , call.data.index);
                }
                break;
            case Function::PLAY_NEXT :
                if(currentSongData.status == PlayStatus::TRACK_NOT_CHOSEN || playlist.size() == 0){
                    res.res = Status::FAILED;
                } else{
                    int next = (currentSongData.index + 1) % playlist.size();
                    currentSongData = CustomDataType(playlist.at(next) , next);
                    res.res = Status::OK;
                }
                break;
            case Function::PLAY_PREVIOUS :
                if(currentSongData.status == PlayStatus::TRACK_NOT_CHOSEN || playlist.size() == 0){
                    res.res = Status::FAILED;
                } else{
                    int next = currentSongData.index - 1;
                    if(next == -1) next = playlist.size() - 1;
                    currentSongData = CustomDataType(playlist.at(next) , next);
                    res.res = Status::OK;
                }
                break;
            default:
                res.data = ERROR_TYPE;
                res.res = Status ::FAILED;
        }
        sender.SendToClient(res);
    }
    return 0;
}