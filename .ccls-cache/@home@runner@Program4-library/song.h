#include "media.h"
#include <iostream>
#include <string>

using namespace std;

class Song : public Media {
private:
  bool top40;
  int weeksNYT;

public:
  Song() : Media() {
    top40 = true;
    weeksNYT = 0;
  }
  Song(char t, string tt, string k, int r, string g, int l, int yr, bool tp)
      : Media(t, tt, k, r, g, l, yr) {
    top40 = tp;
    weeksNYT = 0;
  }

  int getWeeks() { return weeksNYT; }
  void setWeeks(int w) { weeksNYT = w; }
  bool getTop40() { return top40; }
  void setTop40(bool top) { top40 = top; }
  void incrementWeeks(int weeksAdded) { weeksNYT += weeksAdded; }
  void printList() {
    cout << "Song information" << endl;
    cout << "---------------------" << endl;
    cout << "Song title: " << title << endl;
    cout << "Song type: " << keyName << endl;
    cout << "Song rating: " << type << endl;
    cout << "Song genre: " << rating << endl;
    cout << "Song year: " << yearReleased << endl;
    cout << "---------------------" << endl;
  }
};