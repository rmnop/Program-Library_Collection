// Samuel Cabrera
// 10/29/22
// Program to display a library collection of movie, song, and book choices.

#include "function.h"
#include "media.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

  ifstream inFile;
  ofstream outFile;
  // inFile.open("mediaList.csv");
  vector<Media> media;
  vector<Movie> movieCount;
  vector<Song> songCount;
  readDataFile(inFile, outFile, media);
  // use while loop for reading input to display collection
  while (true) {
    char user;
    // char will use print function
    user = printMenu();

    switch (toupper(user)) {
    case 'M':
      printMovieList(media);
      break;
    case 'B':
      printBookList(media);
      break;
    case 'S':
      printSongList(media);
      break;
    case 'A':
      printList(media);
      break;
    case 'F':
      listMovieStars();
      break;
    case 'G':
      findMovie();
      break;
    case 'R':
      randomMovie();
      break;
    case 'D':
      printTop40Songs();
      break;
    case 'T':
      totalList(media);
      break;
    case 'N':
      addContent(media);
      break;
    case 'Q':
      return 1;
    default:
      cout << "Error in input, try again" << endl;
    }
  }
  inFile.close();
  return 1;
}