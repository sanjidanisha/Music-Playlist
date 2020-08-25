#include "functions.h"
using namespace std;
#include <iostream>
#include<string>

//default constructor
Songs::Songs()
{
  songName = "UNKNOWN ";
  artistName = "UNKNOWN ";
  playtime = 0;
  head_ptr = NULL;
  
}
//Parameterized constructor
Songs::Songs(string sName, string arN, int plyT)
{
    this->songName = sName;
    this->artistName = arN;
    this->playtime = plyT;
}

string Songs::getSongName()
{
  return songName;
  
}
void Songs:: setSongName(string newSong)
 {
  songName=newSong;
  
 }
string Songs:: getArtistName()
 {
  return artistName;
  
 }
void Songs:: setArtistName(string newArtist)
 {
  artistName=newArtist;
  
 }
int Songs::getPlayTime()
{
  return playtime;
}
 //set and get for song duration
void Songs::setPlayTime(int newTime)
{
  playtime= newTime;
}

Songs* Songs::getNext()
{
  return nextSongptr;
}

void Songs::setNext(Songs* next){
  nextSongptr=next;
}

void Songs::insertSongs()
{
 //Clear the input buffer.
cin.ignore();
 
//Declare the required variables.
string id, sname, aname;
int slength;


cout << "Enter song's name: ";
getline(cin, sname);

cout << "Enter artist's name: ";
getline(cin, aname);

cout << "Enter song's length ";
cout << "(in seconds): ";
cin >> slength;

//Create the pointer objects.
Songs* newnode = new Songs();
Songs* current;
current = head_ptr;

//Set the values of a node.
newnode->setSongName(sname);
newnode->setArtistName(aname);
newnode->setPlayTime(slength);
newnode->setNext(NULL);

//Check if the list is empty or not.
if (head_ptr == NULL)
{
  //Insert the head node.
  head_ptr = newnode;
}
else
{
  //Traverse the list till the last node.
  while (current->getNext() != NULL)
  {
   current = current->getNext();
  }

  //Insert the new node at the end of the list.
  current->setNext(newnode);
}

//Increment the sum.
init_song++;
}

void Songs::removeSong(string rem) 
{
//Declare the required variables.
int flag = 0;
string songname;

//Create the pointer objects current and prev.
Songs* current;
Songs* prev;

//Initialize the pointer objects.
current = head_ptr;
prev = head_ptr;

do
{
  //Check if the song of the current node matches    
  //with the a song in playlist.
  if (current->getSongName() == rem)
  {
   //Set flag to 1.
   flag = 1;
   break;
  }

  //Keep the track of current and previous node.
  prev = current;
  current = current->getNext();

} while (current != NULL);

//Check if the remove id exists in the list or not.
if (flag == 0)
{
  cout << "There is no such song ";
  cout << rem << " in the playlist." << endl;
}
else
{
  songname = current->getSongName();

  //Check if the node to be removed is the first
  //node.
  if (head_ptr->getSongName() == rem)
  {
   //Remove the head node.
   head_ptr = head_ptr->getNext();
   delete current;
  }
  else
  {
   //Remove the current node and adjust the     
   //links.
   prev->setNext(current->getNext());
   delete current;
  }
  cout << "\"" << songname << "\" removed" << endl;

  
  init_song--;
}
}


void Songs::moveHead(int currpos, int newpos)
{
//Declare and initialize the required variables.
int c = 1;
string songname;

//Create two pointer objects curr and pre.
Songs* curr;
Songs* pre;
Songs* tail;

//Initialize the pointer objects.
curr = head_ptr->getNext();
pre = head_ptr;
tail = head_ptr;
do
{
  //Run the loop till the new position.
  if (c == newpos)
  {
   break;
  }

  //Keep the track of the current and previous    
  //node.
  pre = tail;
  tail = tail->getNext();

  //Increment the value of c.
  c++;

} while (tail != NULL);

songname = head_ptr->getSongName();

//Check if the current position is 1 and new position
//is 2.
if (currpos == 1 && newpos == 2)
{
  //Move the head node to the desired location.
  pre->setNext(tail->getNext());
  tail->setNext(pre);
  head_ptr = tail;
}
else
{
  //Move the head node to the desired location.
  pre->setNext(head_ptr);
  head_ptr->setNext(tail->getNext());
  tail->setNext(curr);
  head_ptr = tail;
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}




void Songs::moveTail(int currpos, int newpos)
{
//Declare and initialize the required variables.
int c;
c = 1;
string songname;

//Create four pointer objects last, tail, curr, and
//prev.
Songs* last;
Songs* curr;
Songs* prev;
Songs* tail;

//Initialize the required pointer objects.
prev = head_ptr;
curr = head_ptr;
last = head_ptr;
tail = head_ptr;

//Traverse the list to the last node.
while (last->getNext() != NULL)
{
  //Keep the track of last and second last node.
  tail = last;
  last = last->getNext();
}
songname = last->getSongName();
do
{
  //Run the loop till the new position.
  if (c == newpos)
  {
   break;
  }

  //Keep the track of the previous and current
  //node.
  prev = curr;
  curr = curr->getNext();

  //Increment the value of the c.
  c++;

} while (curr != NULL);

//Check if new position is at the first node and
//length of the list is 2.
if (newpos == 1 && init_song == 2)
{
  //Move the tail of the list to the desired   
  //location.
  prev->setNext(last->getNext());
  last->setNext(prev);
  head_ptr = last;
}

//Check if new position is at the first node and
//length of the list is greater than 2.
else if (newpos == 1 && init_song>2)
{
  //Move the tail of the list to the desired     
  //location.
  last->setNext(curr->getNext());
  tail->setNext(curr);
  curr->setNext(NULL);
  head_ptr = last;
}

//Check if the new position is at the second last node
//in the list.
else if (newpos == init_song - 1 && newpos < currpos)
{
  //Move the tail of the list to the desired     
  //location.
  prev->setNext(last);
  last->setNext(curr);
  curr->setNext(NULL);
}

//Else part.
else
{
  //Move the tail of the list to the desired     
  //location.
  prev->setNext(last);
  last->setNext(curr->getNext());
  tail->setNext(curr);
  curr->setNext(NULL);
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}

  
//Define the function to move a node to the head of the
//list.
void Songs::moveNodeToHead(int currpos, int newpos)
{
//Declare and initialize the required variables.
int c = 1;
string songname;

//Create 3 pointer objects curr, prev, and tail.
Songs* curr;
Songs* prev;
Songs* tail;

//Initialize the required pointer objects.
tail = head_ptr->getNext();
prev = head_ptr;
curr = head_ptr;
do
{
  //Run the loop till the current position.
  if (c == currpos)
  {
   break;
  }

  //Keep the track of the current and previous    
  //node.
  prev = curr;
  curr = curr->getNext();

  //Increment the value of c.
  c++;

} while (curr != NULL);
songname = curr->getSongName();

//Check if the current position is the second
//position.
if (currpos == 2)
{
  //Swap a node with the head node.
  prev->setNext(curr->getNext());
  curr->setNext(prev);
  head_ptr = curr;
}
else
{
  //Swap a node with the head node.
  prev->setNext(head_ptr);
  head_ptr->setNext(curr->getNext());
  curr->setNext(tail);
  head_ptr = curr;
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}

//Define the function to move a node to the tail of the
//list.
void Songs::moveNodeToTail(int currpos, int newpos)
{
//Declare the required variables.
int c;
c = 1;
string songname;

//Create four pointer objects last, tail,
//curr, and prev.
Songs* last;
Songs* curr;
Songs* prev;
Songs* tail;

//Initialize the required pointer objects.
prev = head_ptr;
curr = head_ptr;
last = head_ptr;
tail = head_ptr;

//Traverse the list to the last node.
while (last->getNext() != NULL)
{
  //Keep the track of the last and previous node.
  tail = last;
  last = last->getNext();
}
do
{
  //Start the loop till the current position.
  if (c == currpos)
  {
   //Break from the loop.
   break;
  }

  //Keep the track of the current and its previous
  //node.
  prev = curr;
  curr = curr->getNext();

  //Increment the value of c.
  c++;

} while (curr != NULL);
songname = curr->getSongName();

//Check if c is equal to the second last position.
if (c == newpos - 1)
{
  //Swap a node with the tail of the list.
  prev->setNext(last);
  last->setNext(curr);
  curr->setNext(NULL);
}

//Check if the current position is the first position.
else if (currpos == 1)
{
  //Swap a node with the tail of the list.
  last->setNext(curr->getNext());
  tail->setNext(curr);
  curr->setNext(NULL);
  head_ptr = last;
}
else
{
  //Swap a node with the tail of the list.
  prev->setNext(last);
  last->setNext(curr->getNext());
  tail->setNext(curr);
  curr->setNext(NULL);
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}

//Define the function to move a node up in the list.
void Songs::moveNodeUp(int currpos, int newpos)
{
//Declare the required variables.
int c = 1;
int s = 1;
string songname;

//Create four pointer objects curr, prev,
//last, and tail.
Songs* curr;
Songs* prev;
Songs* last;
Songs* tail;

//Initialize the required pointer objects.
tail = head_ptr;
last = head_ptr;
prev = head_ptr;
curr = head_ptr;
do
{
  //Run the loop till the current position.
  if (c == currpos)
  {
   break;
  }

  //Keep the track of the current and its previous    
  //node.
  prev = curr;
  curr = curr->getNext();

  //Increment the value of the c.
  c++;

} while (curr != NULL);
do
{
  //Eun the loop till the position.
  if (s == newpos)
  {
   break;
  }

  //Keep the track of the node at new location and    
  //its previous node.
  tail = last;
  last = last->getNext();

  //Incrent the value of s.
  s++;

} while (last != NULL);
songname = last->getSongName();

//Store the last node’s next into the pointer object
//nextnode.
Songs* nextnode;
nextnode = last->getNext();

//Check if the new position is adjacent to the current
//position.
if (newpos == currpos + 1)
{
  //Swap a node with a node at current position    
  //with the node at new position.
  prev->setNext(last);
  last->setNext(curr);
  curr->setNext(nextnode);
}
else
{
  //Swap a node with a node at current position    
  //with the node at new position.
  prev->setNext(last);
  last->setNext(curr->getNext());
  tail->setNext(curr);
  curr->setNext(nextnode);
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}

//Define the function to move a node down in the list.
void Songs::moveNodeDown(int currpos, int newpos)
{
//Declare and initialize the required variables.
int c = 1;
int s = 1;
string songname;

//Create four pointer objects curr, prev,
//last, and tail.
Songs* curr;
Songs* prev;
Songs* last;
Songs* tail;

//Initialize the required pointer objects.
tail = head_ptr;
last = head_ptr;
prev = head_ptr;
curr = head_ptr;
do
{
  //Run the loop till the current position.
  if (c == currpos)
  {
   break;
  }

  //Keep the track of the current and its previous    
  //node.
  prev = curr;
  curr = curr->getNext();

  //Increment the value of the c.
  c++;

} while (curr != NULL);
do
{
  //Run the loop till the new position.
  if (s == newpos)
  {
   break;
  }

  //Keep the track of the node and its previous    
  //node at new location   
  tail = last;
  last = last->getNext();

  //Increment the value of s.
  s++;

} while (last != NULL);
songname = last->getSongName();

//Store the next of the last node into the pointer
//object nextnode.
Songs* nextnode;
nextnode = curr->getNext();

//Check if the new position is adjacent to the current
//position.
if (newpos == currpos - 1)
{
  //Swap the node at current position with the node   
  //at new position.
  tail->setNext(curr);
  curr->setNext(last);
  last->setNext(nextnode);
}
else
{
  //Swap the node at current position with the node   
  //at new position.
  tail->setNext(curr);
  curr->setNext(last->getNext());
  prev->setNext(last);
  last->setNext(nextnode);
}
cout << "\"" << songname << "\" moved to ";
cout << "position " << newpos << endl;
}

//Define the function to change position of songs
void Songs::ChangePosition(int currpos, int newpos)
{
//Check if the both positions are equal or not.
if (currpos == newpos)
{
  cout << "Re-write the distinct positions.";
  cout << endl;
}

//Check if the current and new position are out of
//range or not.
else if (currpos <= 0 || (currpos > init_song && newpos <= 0) || newpos > init_song)
{
  cout << "Positions are out of the range.";
  cout << endl;
}

//Check if the current position is 1 or not.
else if (currpos == 1)
{
  moveHead(currpos, newpos);
}

//Check if the current position is the last position
//or not.
else if (currpos == init_song)
{
  moveTail(currpos, newpos);
}

//Check if the new position is the first position or
//not.
else if (newpos == 1)
{
  moveNodeToHead(currpos, newpos);
}

//Check if the new position is the last position or
//not.
else if (newpos == init_song)
{
  moveNodeToTail(currpos, newpos);
}

//Check if the new position is greater than the
//current position or not.
else if (currpos<newpos)
{
  moveNodeUp(currpos, newpos);
}

//Check if the new position is less than the current
//position or not.
else if (currpos>newpos)
{
  moveNodeDown(currpos, newpos);
}
}


void Songs::printSongsByArtistName(string artistN)
{
  Songs* currentNode;
  currentNode = head_ptr;
  int curr = 1,entry = 0;
  do
  {
  //Check if the artist name of the current node
  //matches with the specific artist name.
  if (currentNode->getArtistName() == artistN)
  {
   //Display the values of the node that
   //matches with the specific artist name.
   cout << "The song Name is : ";
   cout << currentNode->getSongName();
   cout << endl;
   cout << "The Artist Name is: ";
   cout << currentNode->getArtistName();
   cout << endl;
   cout << "The Song Length is ";
   cout << "(in seconds): ";
   cout << currentNode->getPlayTime();
   cout << endl;
   cout << endl;
   entry = 1;
  }

  //Advance the curr node.
  currentNode = currentNode->getNext();

  //Increase the value of the curr by one.
  curr++;

} while (currentNode != NULL);

//Check if the entry of the node is 0 or not.
if (entry == 0)
{
  cout << "No song of the"<< artistN << " in the playlist.";
  cout << endl;
}
}


//Define the function to calculate the total time of the
//playlist.
int Songs::totalTimeOfPlaylist(){
  //Check if the list is empty or not.
  if (head_ptr== NULL){
    return 0;
  }

  //Declare the required variable.
  int total = 0;

  //Create a pointer object cur to traverse the list.
  Songs* cur;

  //Initialize the pointer object.
  cur = head_ptr;

  //Start the while loop till the last node of the list.
  while (cur != NULL){
    //Add the time of the current song in each //iteration.
    total = total + cur->getPlayTime();
    cur = cur->getNext();
  }

  //Return the total time of the playlist.
  return total;
}


//Define the function to display the nodes or songs of the
//list.
void Songs::printSongs(string title)
{
//Create a pointer object to traverse the list.
Songs* cur;

//Initialize the required pointer object.
cur = head_ptr;

//Declare and initialize the required variable.
int count = 1;

cout << title << " - FULL PLAYLIST" << endl;

//Start the do-while loop.
do
{
  //Display the values of a node.
  cout << count << "." << endl;
  //cout << "Unique ID: " << cur->GetID();
 // cout << endl;
  cout << "Song Name: ";
  cout << cur->getSongName() << endl;
  cout << "Artist Name: ";
  cout << cur->getArtistName() << endl;
  cout << "Song Length (in seconds): ";
  cout << cur->getPlayTime() << endl;
  cout << endl;

  //Advance the current node.
  cur = cur->getNext();

  //Increment the count by one.
  count++;

} while (cur != NULL);
}









