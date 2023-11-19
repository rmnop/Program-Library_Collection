#include <iostream>
#include <string>
#include "media.h"


using namespace std;

class Book: public Media {
private: 
  int weeksNYT;
public: 
  Book() : Media() {
    weeksNYT = 0;
  }
  Book(char t, string tt, string k, int r, string g, int l, int yr, int w) : Media(t,tt,k,r,g,l,yr) {
    weeksNYT = w;
  }
  int getWeeks(){return weeksNYT;}
  void setWeeks(int w) {weeksNYT = w;}
  void incrementWeeks(int weeksAdded) {weeksNYT += weeksAdded;}
  void printList() {
    	cout << "Book information" << endl;
	cout << "---------------------" << endl;
	cout << "Book title: " << title << endl;
	cout << "Book author: " << keyName << endl;
	cout << "Book rating: " << type << endl;
	cout << "Book genre: " << rating << endl;
	cout << "Book year: " << yearReleased << endl;
	cout << "---------------------" << endl;
  }
};