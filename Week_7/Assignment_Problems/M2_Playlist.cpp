#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
    string* songs;
    int maxSize;
    int songCount;

public:
    Playlist(int size) {
        maxSize = size;
        songCount = 0;
        songs = new string[maxSize];
    }

    void addSong(string song) {
        if (songCount >= maxSize) {
            cout << "Playlist is full" << endl;
            return;
        }

        songs[songCount] = song;
        songCount++;
    }

    string* getSongs() const {
        string* copy = new string[songCount];

        for (int i = 0; i < songCount; i++) {
            copy[i] = songs[i];
        }

        return copy;
    }

    int getSongCount() const {
        return songCount;
    }

    ~Playlist() {
        delete[] songs;
    }
};

int main() {
    Playlist p(10);

    p.addSong("Song A");
    p.addSong("Song B");

    string* copy = p.getSongs();

    copy[0] = "Hacked";

    string* original = p.getSongs();

    cout << "First song: "
         << original[0] << endl;

    cout << "Song count: "
         << p.getSongCount() << endl;

    delete[] copy;
    delete[] original;

    return 0;
}