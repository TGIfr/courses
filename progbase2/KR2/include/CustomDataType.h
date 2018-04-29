//
// Created by tgifr on 22.05.17.
//

#ifndef KR2_CUSTOMDATATYPE_H
#define KR2_CUSTOMDATATYPE_H
#include <iostream>

//! can be used for sending and receiving
struct Song{
    std::string name;
    std::string singer;
};

typedef struct Song song;

enum PlayStatus{
    TRACK_NOT_CHOSEN,
    STOP,
    PLAYING,
    PAUSE
};

class CustomDataType {
public:
    CustomDataType();

    CustomDataType(std::string name);
    CustomDataType(std::string Name, std::string singer,
                                   int index, PlayStatus playStatus = PlayStatus ::PLAYING, int noiseLevel = 10);
    CustomDataType(Song song,  int index, PlayStatus playStatus = PlayStatus ::PLAYING, int noiseLevel = 10);
    Song song;
    PlayStatus status;
    int index;
    int noiseLevel;

    //! FFTA

};


#endif //KR2_CUSTOMDATATYPE_H
