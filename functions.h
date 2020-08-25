#ifndef MUSIC_PL 
#define MUSIC_PL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

class Songs{
private:
  string songName, artistName;
  int playtime;
    // Head of the list contains no song data, 
    // but points to the song playlist.
  Songs *nextSongptr;
  Songs *head_ptr; // head_ptr

public:
int init_song = 0;
  //default constructor
  Songs();
  //Parameterized Constructor
  Songs(string sName, string arN, int plyT);
  //the member functions of class
  // set and get functions for song name
  string getSongName();
  void setSongName(string newSong);
  string getArtistName(); 
  void setArtistName(string newArtist);
  int getPlayTime(); 
  void setPlayTime(int newTime);

  //The function to retrieve the next song
  Songs *getNext();
  void setNext(Songs *next);


  int totalPlayTime();
  int totalTimeOfPlaylist();
 
  //the function to add song 
  void insertSongs();


  //Songs* insertsong(Songs *headNode) ;// Song Adding function
  void removeSong(string rem);//Song Removing function 
  
  void printSongsByArtistName(string artistN);

  //to print the menu
  void PrintMenu(string title);
  

  void ChangePosition(int currpos, int newpos);

  //All these 6 functions occur in ChangePosition Function
  void moveHead(int currpos, int newpos);
  void moveTail(int currpos, int newpos);
  void moveNodeToHead(int currpos, int newpos);
  void moveNodeToTail(int currpos, int newpos);
  void moveNodeUp(int currpos, int newpos);
  void moveNodeDown(int currpos, int newpos);
  void printSongs (string title);
};

#endif 