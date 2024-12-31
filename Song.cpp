#include "Song.h"

Song::Song(std::string sTitle, std::string sName) 
    : songTitle(sTitle), singerName(sName) {}

Song::~Song() {}

std::string Song::getSongTitle() const { return songTitle; }

std::string Song::getSingerName() const { return singerName; }

void Song::setSongTitle(const std::string& title) { songTitle = title; }

void Song::setSingerName(const std::string& name) { singerName = name; }

std::ostream& operator<<(std::ostream& os, const Song& song) {
    os << "Song Title: " << song.songTitle << ", Singer: " << song.singerName;
    return os;
}
