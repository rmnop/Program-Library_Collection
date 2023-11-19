#include "function.h"
#include "media.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

// static members to count each object
vector<Movie> movieCount;
vector<Book> bookCount;
vector<Song> songCount;

// PRE: Files are open in main & accessible
// POST: Reads the data from csv file and loads the objects into a
// vector<Media>•Produces an error report of any records that have errors
int readDataFile(ifstream &inFile, ofstream &outFile, vector<Media> &media) {
  outFile.open("error_sample.txt");
  // try to open file if error, throw runtime
  try {
    inFile.open("mediaList.csv");
    if (!inFile.is_open()) {
      throw(runtime_error("File won't open"));
    }
  } catch (runtime_error e) {
    cout << e.what() << endl;
    return 1;
  }
  vector<string> line;
  // Media tempMedia;
  int rating, length, yearReleased;
  string inRec, tempString;
  // loop through input file
  while (getline(inFile, inRec)) {
    line.clear();
    stringstream inSS(inRec);
    // push each string onto vector
    while (getline(inSS, tempString, ',')) {
      line.push_back(tempString);
    }
    try {
      rating = stoi(line[3]);
      length = stoi(line[5]);
      yearReleased = stoi(line[6]);
    }

    // displays error file error_sample
    catch (...) {
      outFile << "ERROR: " + line[0] + ", " + line[1] + ", " + line[2] + ", " +
                     line[3] + ", " + line[4] + ", " + line[5] + ", " + line[6]
              << endl;
      outFile << "Previous record has an stoi error" << endl;
      continue;
    }

    if (line[0].at(0) == 'M') {
      Media tempMedia(line[0].at(0), line[1], line[2], rating, line[4], length,
                      yearReleased);

      media.push_back(tempMedia);

      // set stars for movie count
      vector<string> stars;
      for (int i = 7; i < line.size(); i++) {
        stars.push_back(line[i]);
      }

      Movie movie(line[0].at(0), line[1], line[2], rating, line[4], length,
                  yearReleased, stars);
      // stars.push_back(st);
      movieCount.push_back(movie);
    } else if (line[0].at(0) == 'B') {
      Media tempMedia(line[0].at(0), line[1], line[2], rating, line[4], length,
                      yearReleased);
      media.push_back(tempMedia);

    } else if (line[0].at(0) == 'S') {
      Media tempMedia(line[0].at(0), line[1], line[2], rating, line[4], length,
                      yearReleased);
      media.push_back(tempMedia);

      int top40;
      // top40->setTop40(stoi(line[7]));
      Song newSong(line[0].at(0), line[1], line[2], rating, line[4], length,
                   yearReleased, top40);
      songCount.push_back(newSong);
    }
  }
  inFile.close();
  outFile.close();
  return 1;
}

char printMenu() {
  vector<Media> media;
  // create menu
  cout << "Welcome to the Media Library" << endl << endl << endl;
  cout << "\nMENU CHOICES" << endl;
  cout << "M - Print Movie List" << endl;
  cout << "B - Print Book List" << endl;
  cout << "S - Print Song List" << endl;
  cout << "A - Print All Media" << endl;
  cout << "F - Find the Movie the star is in" << endl;
  cout << "G - Print stars for a given movie" << endl;
  cout << "R - 4 randomized movie for you to watch" << endl;
  cout << "D - Top 40 rated songs" << endl;
  cout << "N - Add New Media" << endl;
  cout << "T - Print Media Counts" << endl;
  cout << "Q - Quit" << endl;
  cout << "Enter your choice: ";

  while (true) {
    char userInput;
    string convString;
    cin >> convString;
    // convert to string to read first line
    userInput = convString[0];

    // if error inputting char it retries input
    if (cin.fail()) {
      cin.clear();
      continue;
    }

    // if user types anything other than char, print runtime error
    try {
      if (!(userInput = toupper(userInput))) {
        throw(runtime_error("Invalid input.Please try again\n"));
      }
    } catch (runtime_error(e)) {
      cout << e.what() << endl;
      continue;
    }

    // each case is for each function to print out each list from the library,
    // use main to print out the functions
    switch (userInput) {
    case 'M':
    case 'B':
    case 'S':
    case 'A':
    case 'F':
    case 'G':
    case 'R':
    case 'D':
    case 'N':
    case 'T':
    case 'Q':
      // ignores previos input for new input
      cin.ignore(1000, '\n');
      return userInput;

    default:
      cout << "Invalid input.Please try again\n " << endl;
      cout << "Enter your choice: ";
      continue;
    }
  }
}

// print booklist
void printBookList(vector<Media> media) {
  cout << endl << endl << right << setw(30) << "YOUR BOOK LIST" << endl << endl;
  cout << "#" << setw(20) << "TITLE" << setw(25) << "YEAR" << setw(25)
       << "RATING" << endl;
  // prints out size of list by size()
  for (int i = 0; i < media.size(); i++) {
    if (toupper(media.at(i).getType() == 'B')) {
      cout << left << setw(3) << i + 1 << setw(40) << media.at(i).getTitle()
           << setw(2) << media.at(i).getYearReleased() << right << setw(20)
           << media.at(i).getRating();
      cout << endl;
    }
  }
}

// print songlist
void printSongList(vector<Media> media) {
  cout << endl << endl << right << setw(30) << "YOUR SONG LIST" << endl << endl;
  cout << "#" << setw(20) << "TITLE" << setw(25) << "YEAR" << setw(25)
       << "RATING" << endl;
  // prints out size of list by size()
  for (int i = 0; i < media.size(); i++) {
    if (toupper(media.at(i).getType() == 'S')) {
      cout << left << setw(3) << i + 1 << setw(40) << media.at(i).getTitle()
           << setw(2) << media.at(i).getYearReleased() << right << setw(20)
           << media.at(i).getRating();
      cout << endl;
    }
  }
}

// print movie list
void printMovieList(vector<Media> media) {
  cout << endl
       << endl
       << right << setw(30) << "YOUR MOVIE LIST" << endl
       << endl;
  cout << "#" << setw(20) << "TITLE" << setw(25) << "YEAR" << setw(25)
       << "RATING" << endl;
  // prints out size of list by size()
  for (int i = 0; i < media.size(); i++) {
    if (toupper(media.at(i).getType() == 'M')) {
      cout << left << setw(3) << i + 1 << setw(40) << media.at(i).getTitle()
           << setw(2) << media.at(i).getYearReleased() << right << setw(20)
           << media.at(i).getRating();
      cout << endl;
    }
  }
}

// print total list in collection
void printList(vector<Media> media) {
  cout << endl << endl << right << setw(30) << "TOTAL LIST" << endl << endl;
  cout << "#" << setw(20) << "TITLE" << setw(25) << "YEAR" << setw(25)
       << "RATING" << endl;
  for (int i = 0; i < media.size(); i++) {
    cout << left << setw(3) << i + 1 << setw(40) << media.at(i).getTitle()
         << setw(2) << media.at(i).getYearReleased() << right << setw(20)
         << media.at(i).getRating();
    cout << endl;
  }
}

// list stars in movies
void listMovieStars() {
  string name;
  cout << "Enter a movie title to list star actors/actresses: ";
  getline(cin, name);
  for (int i = 0; i < movieCount.size(); i++) {
    Movie movie = movieCount[i];
    if (toupper(movie.getTitle() == name)) {
      vector<string> stars = movie.getStars();
      if (stars.size() > 0) {
        cout << "THE STARS OF THE MOVIE " << movie.getTitle()
             << " ARE:" << endl;
        cout << "=================" << endl;
        for (int j = 0; j < stars.size(); j++) {
          cout << stars.at(j) << endl;
        }
      }
    }
  }
}

// by typing an actor name from the movie list it will display the stars in the
// movie
void findMovie() {
  string temp;
  vector<string> name;
  cout << "Enter star actor/actresses to find movies they're starred in: ";
  getline(cin, temp);
  for (int i = 0; i < movieCount.size(); i++) {
    Movie movie = movieCount.at(i);
    vector<string> stars = movie.getStars();
    for (int j = 0; j < stars.size(); j++) {
      if (temp == stars.at(j)) {
        name.push_back(movie.getTitle());
      }
    }
  }

  cout << "+++++++++++++++++++++++++++++" << endl;
  cout << temp << " appears in the following movie(s):" << endl;
  for (int j = 0; j < name.size(); j++) {
    cout << name.at(j) << endl;
  }
}

// randomizes 4 movies to watch
void randomMovie() {
  int k, listsize;
  srand(time(NULL));
  cout << "Here are 4 random movies from the Movie List: " << endl;
  cout << "=========================" << endl;
  cout << "#" << setw(20) << "TITLE" << setw(25) << "YEAR" << setw(25)
       << "RATING" << endl;
  srand(time(NULL));

  listsize = movieCount.size();

  for (int i = 0; i < 4; i++) {
    k = rand() % listsize;
    cout << left << setw(3) << i + 1 << setw(40) << movieCount.at(k).getTitle()
         << setw(2) << movieCount.at(k).getYearReleased() << right << setw(20)
         << movieCount.at(k).getRating();
    cout << endl;
  }
}

// By using boolen value, get the top 40 songs and print the list of top40
void printTop40Songs() {
  int i, listSize;
  cout << "TOP SONG LIST" << endl;
  cout << endl;
  cout << "#" << setw(20) << "TITLE"
       << "                                YEAR  "
       << " RATING" << endl;

  listSize = songCount.size();

  for (i = 0; i < listSize; i++) {
    if (songCount.at(i).getTop40() == true) {
      cout << left << setw(3) << i + 1 << setw(50) << songCount.at(i).getTitle()
           << setw(10) << songCount.at(i).getYearReleased() << setw(20)
           << songCount.at(i).getRating();
      cout << endl;
    }
  }
}

void totalList(vector<Media> media) {
  // use counts to print out for each collection
  int movieCount = 0;
  int bookCount = 0;
  int songCount = 0;
  int total = 0;
  // prints out in for loop
  for (int i = 0; i < media.size(); i++) {
    if (media.at(i).getType() == 'M') {
      movieCount++;
      total++;
    }
    if (media.at(i).getType() == 'B') {
      bookCount++;
      total++;
    }
    if (media.at(i).getType() == 'S') {
      songCount++;
      total++;
    }
  }
  cout << endl << endl << "YOUR MEDIA LIBRARY" << endl << endl;
  cout << "#" << setw(7) << "TYPE" << endl;
  cout << movieCount << setw(8) << "Movies" << endl;
  cout << bookCount << setw(7) << "Books" << endl;
  cout << songCount << setw(7) << "Songs" << endl;
  cout << total << setw(7) << "Total" << endl;
}

void addContent(vector<Media> &media) {
  // use class members
  char type;
  string title;
  string keyName;
  int rating;
  string genre;
  int length;
  int yearReleased;
  Media newMedia;

  // ask user to input new media m,s, or b
  cout << "Enter type of media you would like to add: ";
  cin >> type;
  type = toupper(type);

  // if inputs wrong thenretry
  while (type != 'M' && type != 'B' && type != 'S') {
    cout << "This is not of one the collections in the list, please choose: M, "
            "B, or S"
         << endl;
    cout << "Enter type of media you would like to add: ";
    cin >> type;
    type = toupper(type);
  }
  // class will initialize type that was inputted
  newMedia.setType(type);

  cin.ignore();

  // initializes title
  cout << "Enter Title: ";
  getline(cin, title);
  newMedia.setTitle(title);

  // initializes keyName
  cout << "Enter Name (artist ,director, author): ";
  getline(cin, keyName);
  newMedia.setKeyName(keyName);

  // initializes genre
  cout << "Enter Genre: ";
  getline(cin, genre);
  newMedia.setGenre(genre);

  // initializes rating
  cout << "Enter rating: ";
  cin >> rating;

  // if there is no int, then throw runtime error
  if (!cin) {
    throw runtime_error("Rating invalid.");
    cout << endl;
  }

  // retyr if int is not within range
  while (rating < 1 || rating > 10) {
    cout << "Rating invalid - Choose rating from 1-10" << endl;
    cout << "Enter rating: ";
    cin >> rating;
  }

  // intializes rating
  newMedia.setRating(rating);

  // Asks user to enter a length above 0 and sets it
  cout << "Enter Length: ";
  cin >> length;
  if (!cin) {
    throw runtime_error("Length invalid.");
    cout << endl;
  }

  while (length < 0) {
    cout << "length invalid - try again" << endl;
    cout << "Enter Length: ";
    cin >> length;
  }
  newMedia.setLength(length);

  // extra credit: enterfrom 1900 - 2023
  cout << "Enter year: ";
  cin >> yearReleased;
  if (!cin) {
    cin.clear();
    cin.ignore(1000, '\n');
    throw runtime_error("Year invalid. Please enter a year: ");
    cin >> yearReleased;
  }
  // can only print year from 1900 - 2023: extra credit
  while (yearReleased <= 1900 || yearReleased >= 2023) {
    cout << "Year Invalid, must be from 1900-2023" << endl;
    cout << "Enter Year: ";
    cin >> yearReleased;
  }
  newMedia.setYearReleased(yearReleased);

  // adds evething inputted into vector
  media.push_back(newMedia);

  cout << newMedia.getTitle() << " was added to your library" << endl;
}
