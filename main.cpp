#include "playlist.h"
#include <cassert>
#include <iostream>

using namespace std;

//The test to run the program
void test1() {
    Playlist playlist("Deep Focus");
    playlist.addSong("Under The Wind");
    playlist.addSong("Safe And Sound");
    playlist.addSong("alpha waves");
    playlist.addSong("Dawning");
    playlist.addSong("Curiosity");
    playlist.addSong("Coda");
    playlist.addSong("When They Come");
    playlist.addSong("Event Horizon");
    playlist.addSong("Laugavegur");
    playlist.addSong("The Discovery");

    cout << "List all songs:" << endl;
    playlist.listAllSongs();

    cout << "List 0 shuffled songs:" << endl;
    playlist.listShuffledSongs(0);

    cout << "List 1 shuffled songs:" << endl;
    playlist.listShuffledSongs(1);

    cout << "List 10 shuffled songs:" << endl;
    playlist.listShuffledSongs(10);

    // should generate already in playlist message and return true
    bool result = playlist.isInPlaylist("Dawning");
    assert(result);

    // cannot add book twice, result should be false
    result = playlist.addSong("Dawning");
    assert(!result);

    // test remove, result should be true
    result = playlist.removeSong("Dawning");
    assert(result);

    // not in library, result should be false
    result = playlist.isInPlaylist("Dawning");
    assert(!result);

    // cannot remove twice, result should be false
    result = playlist.removeSong("Dawning");
    assert(!result);

    cout << "List all songs using << operator:" << endl << playlist << endl;
}

//To run all the test
void testAll() {
    cout << "Run all tests." << endl;
    test1();
    cout << "Successfully completed all tests." << endl;
}

int main() {
    testAll();
    return 0;
}