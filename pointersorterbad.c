// Naeem Hossain
// Systems
// February 5, 2017
// Asst0: String Sorting

// You will write a rather simple program to sort words given in a 
// single input string. Your code will take a single, long input string 
// that contains all words to be sorted, break them out into individual strings,
// sort them, and output them one per line in descending alphabetical order.
// Separated by non alphabet chars.

//(EFFICIENCY DOES NOT MATTER FAM)
//1) Create empty LinkedList structure
//2) Store words from text file into LinkedList
//3) Sort LinkedList alphabetically
//4) Print results
//5) ???
//6) Profit

//ERROR CHECK:
//gcc -g pointersorter.c
//valgrind ./a.out


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
node_t *add (node_t *head, char word[])
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
 
void print (node_t *head)
{
  while ( head != NULL ) {
    printf ( "\n%s ", head->words );
    head = head->next;
  }
  printf ( "\n" );
}

//Swaps nodes in the LinkedList for sorting
void swap(node_t *a, node_t *b)
{	
	
	//node_t *tmp;
	//tmp = malloc ( sizeof *head );
	//node_t *prev = head;
	//while(prev->next != a)
	//{
	//	prev = prev->next;
	//} 
	//tmp->next = b->next;
	//tmp->words == a->words;
	//b->next = tmp;
	//prev->next = b;
	//free(tmp);
	
	
	//char* nemo = (char*) malloc(20*sizeof(char));
	node_t *temp;
	temp = malloc ( sizeof *temp->next );
	strcpy(a->words, temp->words);
	strcpy(b->words, a->words);
	strcpy(temp->words, b->words);
	free(temp->next);
}

//Sorts LinkedList and then calls from print
node_t *sort(node_t *head, char word[])
{		
	
	int hasBeenSwapped = 0;
	node_t *ptr;
	node_t *ptr2 = NULL;
	
	do
	{
		hasBeenSwapped = 0;
		ptr = head;
		
		while(ptr->next != ptr2)
		{
			if((strcmp( ptr->words, ptr->next->words )) > 0)
			{
				swap(ptr, ptr->next);
				hasBeenSwapped = 1;
			}
			ptr = ptr->next;
		}
		ptr2 = ptr;
	}
	while(hasBeenSwapped);
	return head;
}

int main (int argc, char **argv)
{
	char *input = argv[1];
  	char c;
 	int i= 0;
    int j = 0;
	char word[50];
	node_t *list = NULL;
	
	if(argc != 1)
 	{
 		printf("usage: pointersorter.c input_string\n");
 		return 1;	
 	}
 
	FILE *f = fopen ( "testcases.txt", "r" );
	
  	for (i = 0; ( c = fgetc(f) ) != EOF; ++i) 
  	{
    	if (isalpha (c))
    	{
     		word[j++] = tolower(c);
    	}  
    	else
    	{
    	//putchar('\n');
      	word[j++] = '\0';
      	list = add ( list, word );
     	j = 0;
    	}
  	}
  	list = sort (list, word);
  	print(list);
  	fclose (f);
  	return 0;
}


//Testing input from text files
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
 	
 	if(argc != 1)
 	{
 		printf("usage: pointersorter.c input_string\n");
 		return 1;	
 	}
 	
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

	

/*





*/


