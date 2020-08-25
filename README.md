# Music-Playlist 
=> The goal is to create a program to simulate an online music playlist such as “Spotify” for the music discovery and recommendations of the playlist.
=> To use an appropriate data structure to sort, search and manipulate user’s songs, in this case a linked list.
=> To gather an understanding of  how pointers work in our playlist functions, such as getting the next song and understanding how linked list allows users to simultaneously play songs, add new songs and delete any unwanted songs.
=> Linked lists are both faster and no memory is going into waste, unlike arrays. 

Limitations of a Linked List 
=> A drawback of choosing a linked list is how the program must traverse the list to get to a specific index, resulting in the loss of memory. 
=> Linked lists can have difficulties with reverse traversing—while  doubly linked lists can be a solution to this problem, they waste space on the allocation of a back pointer.
=> Binary search is not possible with linked lists, meaning a search has to start with the first node, making its way through the list

The features available in this playlist are:
=> Adding a song 
=> Removing a song 
=> Changing the position of a song 
=> Displaying songs by a specific artist 
=> Display the total time of playlist 
=> Display all songs in playlist 
=> Exiting the playlist 
=> This is all displayed in the PrintMenu() function at the beginning of the program
