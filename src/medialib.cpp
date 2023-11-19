#include "media.h"

using namespace std;

// sets each variable
Media::Media() {
  type = ' ';
  title = " ";
  keyName = " ";
  rating = 0;
  genre = " ";
  length = 0;
  yearReleased = 0;
}

// each values is ibstantiated
Media::Media(char type, string title, string keyName, int rating, string genre,
             int length, int yearReleased) {
  this->type = type;
  this->title = title;
  this->keyName = keyName;
  this->rating = rating;
  this->genre = genre;
  this->length = length;
  this->yearReleased = yearReleased;
}
// setters
void Media::setType(char type) { this->type = type; }
void Media::setTitle(string title) { this->title = title; }
void Media::setKeyName(string keyName) { this->keyName = keyName; }
void Media::setRating(int rating) { this->rating = rating; }
void Media::setGenre(string genre) { this->genre = genre; }
void Media::setLength(int length) { this->length = length; }
void Media::setYearReleased(int yearReleased) {
  this->yearReleased = yearReleased;
}
// getters
char Media::getType() { return type; }
string Media::getTitle() { return title; }
string Media::getKeyName() { return keyName; }
int Media::getRating() { return rating; }
string Media::getGenre() { return genre; }
int Media::getLength() { return length; }
int Media::getYearReleased() { return yearReleased; }

void Media::printList() {}

