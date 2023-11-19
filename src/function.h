#include "book.h"
#include "media.h"
#include "movie.h"
#include "song.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

// pre:
int readDataFile(ifstream &inFile, ofstream &outFile, vector<Media> &media);
// post: reads file in order to store file into class

// prints option
char printMenu();

// prints book list
void printBookList(vector<Media> media);

void printSongList(vector<Media> media);
// POST:  Each of these functions will printthe appropriatelist (see below)This
// is a partial list

// pre
void printMovieList(vector<Media> media);
// POST:   Each of these functions will printthe appropriatelist (see below)This
// is a partial list

// PRE:
void printList(vector<Media> media);
// POST:   Each of these functions will printthe appropriatelist (see below)This
// is a partial list

// static class array to print total list after being updated;
void totalList(vector<Media> media);

// adds new collection to library
void addContent(vector<Media> &addContent);

void listMovieStars();

void findMovie();

void randomMovie();

void printTop40Songs();
