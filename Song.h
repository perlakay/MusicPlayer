#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

class Song {
private:
    std::string songTitle;
    std::string singerName;

public:
    Song(std::string sTitle = "", std::string sName = ""); // Constructor
    ~Song(); // Destructor

    std::string getSongTitle() const;
    std::string getSingerName() const;

    void setSongTitle(const std::string& title);
    void setSingerName(const std::string& name);

    friend std::ostream& operator<<(std::ostream& os, const Song& song);
};

#endif
