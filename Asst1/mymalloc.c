//Naeem Hossain
//Malloc
//February 26, 2017

// 1) Set up a char array of 5000 bytes 
// 2) Put metadata before each chunk to be malloced in the char array
// 3) Store values at certain points in the array ex) '4 bytes stored here'
// 4) 
// 5)
// 6)
// 7)
// 8)
// 9)
// 10)

#include "malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 5000
#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )

//Creates the character array with 5000 'bytes'
static char myblock[BLOCK_SIZE];

//Create the metadata struct over here
//IDEAS:
//a. Create a hashtable and utilize static variables
//(static vars still exist after usage, so they're useful for metadatas)
//b. 

struct metaData
{
	struct metaData *next;
	size_t is_free, size, line_num, pattern;
	string file;
};








