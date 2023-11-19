#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Media {
public:
  Media();

  Media(char type, string title, string keyName, int rating, string genre,
        int length, int yearReleased);

  // getter constructor
  char getType();
  string getTitle();
  string getKeyName();
  int getRating();
  string getGenre();
  int getLength();
  int getYearReleased();

  // setter constructor
  void setType(char type);
  void setTitle(string title);
  void setKeyName(string keyName);
  void setRating(int rating);
  void setGenre(string genre);
  void setLength(int length);
  void setYearReleased(int yearReleased);

  // virtual function implemented to child classes to print list
  virtual void printList();

  // private members
protected:
  char type;
  string title;
  string keyName;
  int rating;
  string genre;
  int length;
  int yearReleased;

static int mediaCount;
static int bookCount;
static int movieCount;
static int songCount;
};

