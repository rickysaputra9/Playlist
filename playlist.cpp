// Playlist class demonstrating partially filled arrays
// Can add/remove songs from playlist
// find songs in playlist

#include "playlist.h"
#include <iostream>

//initialize variable and uses array
static const int MAX = 100;
string nameofSongs[MAX];
int numberofSongs;

// constructor with default name
Playlist::Playlist(const string& name) {
    cout<< "Playlist " << name << " created ";
    cout << "\n";
}

// destructor
// nothing on heap
Playlist::~Playlist() {
    // destructor
}

// true if song found in playlist
bool Playlist::isInPlaylist(const string& song) const {
    for(int i=0; i<numberofSongs;i++){
        if(nameofSongs[i] == song){
            return true;
        }
    }
    return false;
}

// add a new song
// return true if successful, false if song already in playlist
bool Playlist::addSong(const string &song) {
    if(isInPlaylist(song)){
        return false;
    }else{
        nameofSongs[numberofSongs] = song;
        numberofSongs++;
        return true;
    }
}

// remove a song
// return true if successfully removed, false if song not in playlist
bool Playlist::removeSong(const string &song) {
    if(isInPlaylist(song)){
        nameofSongs[findSong(song)] = nameofSongs[numberofSongs];
        numberofSongs--;
        return true;
    }else {
        return false;
    }
}

// list all songs
void Playlist::listAllSongs() const {
    for(int i=0; i<numberofSongs;i++){
        cout << nameofSongs[i];
        cout<< "\n";
    }
}

// list shuffled songs with count
void Playlist::listShuffledSongs(unsigned int count) const {
    std::srand(time(nullptr)); // use current time as seed for random generator
    int randomVariable = rand() % numberofSongs;
    for(int i=0; i<count;i++) {
        cout << nameofSongs[randomVariable];
        cout << "\n";
        randomVariable = rand() % numberofSongs;
    }
}

//To find the index of the song
int Playlist::findSong(const string &song) const{
    for(int i=0;i<numberofSongs; i++){
        if(nameofSongs[i] == song){
            return i;
        }
    }
    return -1;
}

//List the song
ostream& operator<<(ostream& Out, const Playlist& playlist) {
    playlist.listAllSongs();
    return Out;
}