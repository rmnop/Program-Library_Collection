#include "media.h"
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Movie : public Media {
private:
  vector<string> stars;

public:
  Movie():Media() {
    stars = {};
  }
//constructor
  Movie(char t, string tt, string k, int r, string g, int l, int yr, vector<string> s) : Media(t,tt,k,r,g,l,yr) {
    stars = s;
  }
//getter and setters
  vector<string>getStars(){return stars;}
  void setStars(vector<string> s) {stars = s;}
//abstract class
  void printList() {
    	cout << "Movie information" << endl;
	cout << "---------------------" << endl;
	cout << "Movie title: " << title << endl;
	cout << "Movie type: " << type << endl;
	cout << "Movie rating: " << type << endl;
	cout << "Movie genre: " << rating << endl;
	cout << "Movie year: " << yearReleased << endl;
	cout << "---------------------" << endl;
  }
  
};