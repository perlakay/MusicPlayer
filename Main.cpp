#include "MusicPlayer.h"

int main() {
    MusicPlayer player("My Music Player");

    player.addSong(Song("Saiyan", "Stray Kids"));
    player.addSong(Song("Without You", "Osn"));
    player.addSong(Song("Not a Rapper", "Marz23"));

    std::cout << "Initial Playback:" << std::endl;
    player.play();

    std::cout << "\nPlaying Next Songs:" << std::endl;
    player.next();
    player.next();

    std::cout << "\nPlaying Previous Song:" << std::endl;
    player.previous();

    std::cout << "\nPlaylist Forward:" << std::endl;
    player.print(true);

    std::cout << "\nPlaylist Reverse:" << std::endl;
    player.print(false);

    std::cout << "\nRemoving Current Song:" << std::endl;
    player.removeSong();
    player.play();

    std::cout << "\nFinal Playlist Forward:" << std::endl;
    player.print(true);

    return 0;
}
