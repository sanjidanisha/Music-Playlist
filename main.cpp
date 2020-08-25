// Group members:
// 1) Ushna Arshid
// 2) Farah Sultana
// 3) Gilianny Jimenez
// 4) Sanjida Nisha 

#include "functions.h"
#include<iostream>
#include <string> 
using namespace std;

void PrintPlaylistMenu(string title)
{
//Display the playlist menu.
cout << "Welcome to our playlist " <<"||||||" << title  << "||||||" << endl;
cout << "Choose an option to continue:" << endl;
cout << "Enter 'a' to Add a song." << endl; 
cout << "Enter 'r' to Remove a song." << endl;
cout << "Enter 'c' to Change the position of song." << endl;
cout << "Enter 's' to see a specific song by a specific artist." << endl;
cout << "Enter 't' to find total time of our playlist (in seconds)."<< endl;
cout << "Enter 'o' to view the full playlist." << endl;
cout << "Enter 'q' to quit." << endl;
}

int main(){
  char choice;
  string rem, artistName, title;
  int pos, newpos, total;

  Songs ourList;

  cout << "Enter the title of the playlist: ";
  getline(cin, title);

while (true)
{
  PrintPlaylistMenu(title);

  cout << "Choose an option: ";
  cin >> choice;

  switch (choice)
  {

  case 'a':

   //Call the function InsertAfter to add a
   //song in the playlist.
   cout << "ADD SONG" << endl;
   ourList.insertSongs();
   break;

  case 'r':

   //Check if the list is empty or not.
   if (ourList.init_song== 0)
   {
    cout << "Playlist is empty." << endl;
   }
   else
   {
    cout << "REMOVE SONG" << endl;

    //Clear the input buffer.
    cin.ignore();

    cout << "Enter song name: ";
    getline(cin, rem );

    //Call the RemoveSong function to
    //remove a song from the playlist.
    ourList.removeSong(rem) ;
   }
   break;

  case 'c':

   //Check if the list is empty or not.
   if (ourList.init_song == 0)
   {
    cout << "Playlist is empty. Please ";
    cout << "add songs in the playlist.";
    cout << endl;
   }
   else
   {
    cout << "CHANGE POSITION OF SONG";
    cout << endl;

    cout << "Enter song's ";
    cout << "current position: ";
    cin >> pos;
    cout << "Enter new position for ";
    cout << "song: ";
    cin >> newpos;

    //Call the function ChangePosition to
    //change the position of a song.
    ourList.ChangePosition(pos, newpos);
   }
   break;

  case 's':

   //Check if the list is empty or not.
   if (ourList.init_song == 0)
   {
    cout << "Playlist is empty." << endl;
   }
   else
   {

    //Clear the input buffer.
    cin.ignore();
    cout << "OUTPUT SONGS BY ";
    cout << "SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name: ";
    getline(cin, artistName);

    //Call PrintSongsByArtistName.
    ourList.printSongsByArtistName(artistName);
   }
   break;

  case 't':

   //Display the total time of the playlist.
   cout << "OUTPUT TOTAL TIME OF PLAYLIST ";
   cout << "(IN SECONDS)" << endl;
   total = ourList.totalTimeOfPlaylist();
   cout << "Total time: " << total;
   cout << "seconds" << endl;
   break;

  case 'o':

   //Check if the list is empty or not.
   if (ourList.init_song == 0)
   {
    cout << "Playlist is empty." << endl;
   }
   else
   {
    ourList.printSongs(title);
   }
   break;

  case 'q':

   //Terminate the program if user enters q.
   exit(0);
   break;

  default:
   cout << "Invalid Choice" << endl;
  }
}


  return 0;
}

