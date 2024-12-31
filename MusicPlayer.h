#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "CircleDLinkedList.h"

class MusicPlayer {
private:
    std::string type;
    CircleDLinkedList playlist;

public:
    MusicPlayer(std::string t = "Default");
    virtual ~MusicPlayer();

    void play();
    void next();
    void previous();
    void addSong(const Song& song);
    void removeSong();

    int size() const;
    bool empty() const;
    Song getCurrentSong() const;
    void print(bool forward) const;
};

#endif
