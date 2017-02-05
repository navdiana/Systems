// Naeem Hossain
// Systems
// February 5, 2017
// Asst0: String Sorting

// You will write a rather simple program to sort words given in a 
// single input string. Your code will take a single, long input string 
// that contains all words to be sorted, break them out into individual strings,
// sort them, and output them one per line in descending alphabetical order.
//Separated by non alphabet chars

// 1) Create empty hashtable
// 2) Go through string, turn all non-alphabet chars into spaces
// 3) Read strings into program
// 4) Store strings into hash table
// 5) Sorting
// 6) Return result


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int entries;
  char words[50];
  struct node *next;
} node_t;


//Add function for LinkedList
node_t *add ( node_t *head, char word[] )
{
  node_t *current = NULL;
 
  if ( head == NULL ) {
    head = malloc ( sizeof *head );       
    head->next = NULL;
  }
  else {
    current = malloc ( sizeof *current->next );
    current->next = head;
    head = current;
  }
 
  strcpy ( head->words, word );
  return head;
}
 
void PrintList ( node_t *head )
{
  while ( head != NULL ) {
    printf ( "%s ", head->words );
    head = head->next;
  }
  printf ( "\n" );
}

//Sorts LinkedList and then calls from print
node_t *sort


int main (void)
{
  char c;
  int i= 0;
  int j = 0;
  char word[50];
  node_t *list = NULL;
 
  FILE *src = fopen ( "testcases.txt", "r" );
 
  for ( i = 0; ( c = fgetc ( src ) ) != EOF; ++i ) {
    if ( isalpha ( c ) )
      word[j++] = tolower ( c );
    else {
      word[j++] = '\0';
      list = add ( list, word );
      //list = sort (list, word);
      j = 0;
    }
  }
 
  PrintList ( list );
  fclose ( src );
 
  return 0;
}
/*
int main (int argc, char **argv)
{

	//LinkedList & File setup
    int c;
    char *input = argv[1];
    FILE *input_file;
    node *head, *ptr;
 	char c;
    head = NULL;
 	ptr = NULL;
 	
 	
    input_file = fopen("testcases.txt", "r");
	
	//Error check if file is empty
    if (input_file == 0)
    {
        //fopen returns 0, the NULL pointer, on failure
        perror("Canot open input file\n");
        exit(-1);

	} else
    {
        int found_word = 0;
        while ((c =fgetc(input_file)) != EOF )
        {
            //if it's an alpha, convert it to lower case
            if (isalpha(c))
            {
                found_word = 1;
                //c = tolower(c);
                putchar(c);
            }
            else {
                if (found_word) {
                    putchar('\n');
                    found_word=0;
                }
            }

        }
    }
    
    fclose(input_file);
    printf("\n");
	
	//free data in LinkedList node first
	//free actual node of LinkedList
    return 0;
}
*/
	


