//
// Created by tgifr on 22.05.17.
//

//! interface for client


#ifndef KR2_REMOTE_H
#define KR2_REMOTE_H

#include "Sender.h"
#include "CustomDataType.h"
#include <iostream>


class Remote {
private:
public:
    //some methods for user
    std::string PrintAndReturnWhatPrinted(CustomDataType);
    void DeleteSong(int index);
    void AddSong(Song song);
    void Pause();
    void Stop();
    void PlayNext();
    void PlayPrevious();
    PlayStatus GetStatus();
    void Start(int index);
    Song GetPlayed();
    int GetLoud();
    void SetLoud(int loud);


};


#endif //KR2_REMOTE_H
