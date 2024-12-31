#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(std::string t) : type(t) {}

MusicPlayer::~MusicPlayer() {}

void MusicPlayer::play() {
    try {
        std::cout << "Playing: " << playlist.getCurrentSong() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void MusicPlayer::next() {
    playlist.advance();
    play();
}

void MusicPlayer::previous() {
    playlist.retreat();
    play();
}

void MusicPlayer::addSong(const Song& song) {
    playlist.add(song);
}

void MusicPlayer::removeSong() {
    playlist.remove();
}

int MusicPlayer::size() const {
    return playlist.size();
}

bool MusicPlayer::empty() const {
    return playlist.empty();
}

Song MusicPlayer::getCurrentSong() const {
    return playlist.getCurrentSong();
}

void MusicPlayer::print(bool forward) const {
    playlist.print(forward);
}
