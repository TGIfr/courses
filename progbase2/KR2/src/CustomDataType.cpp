//
// Created by tgifr on 22.05.17.
//

#include "../include/CustomDataType.h"
#include "../include/Sender.h"

CustomDataType::CustomDataType() {

}

CustomDataType::CustomDataType(std::string name) {
    this->song.name = name;
}

CustomDataType::CustomDataType(std::string Name, std::string singer,
                               int index, PlayStatus playStatus , int noiseLevel ){
    this->song.name = Name;
    this->song.singer = singer;
    this->status = playStatus;
    this->index = index;
    this->noiseLevel = noiseLevel;
}
CustomDataType::CustomDataType(Song song,  int index, PlayStatus playStatus , int noiseLevel ){
    this->song = song;
    this->status = playStatus;
    this->index = index;
    this->noiseLevel = noiseLevel;
}

