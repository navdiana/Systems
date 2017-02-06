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
//1) Create empty HashTable with indexes A, a, B, b, ... Z, z
//2) Input words into the hashtable, indices are based on alphabet values
//3) hashtable is already sorted
//4) Print results
//5) ???
//6) Profit

//ERROR CHECK:
//gcc -g pointersorter.c
//valgrind ./a.out

//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Structure creation----------
/*
typedef struct node
{
  int entries;
  char words[50];
  struct node *next;
} Node*;
*/

typedef struct node
{
	int entries;
	char* word;
	struct node* next;
}Node;

typedef struct HashTable
{
	Node** table;
	int numFilled;
}hashTable;

hashTable* addHT()
{
	hashTable* nemo = (hashTable*)malloc(sizeof(hashTable));
	//52 is twice size of alphabet, including capitalized chars
	nemo->table = (Node**)malloc(52*sizeof(Node*));
	int i;
	for (i=0; i<52; i++)
	{
		nemo->table[i] = NULL;
	}
	nemo->numFilled = 0;
	return nemo;
}

Node* addStringNode(char* word)
{
	Node* myNode = (Node*)malloc(sizeof(Node));
	myNode -> word = strdup(word);
	myNode -> next = NULL;
	return myNode;
}


//Structure creation----------

//sorts entries within the linked list of the hashtable array
hashTable* sorter(Node* root)
{
	
	int address;
	int start;
	hashTable* organizer = addHT();
	while(root!=NULL)
	{
		
		start = root->word[0];
		//Deals with ASCII values of capitalized letters
		//versus non capitalized letters
		if(start<=90)
			address = 2*(start % 65);
		else
			address = 2*(start-96)-1;
		Node* node = addStringNode(root->word);
		if(organizer->table[address]==NULL || strcmp(organizer->table[address]->word, node->word)>=0)
			{
				node->next = organizer->table[address];
				organizer->table[address] = node;
			}
			else
			{
				Node* curr = organizer->table[address];
				Node* prev = organizer->table[address];
				while(curr!=NULL && strcmp(curr->word, node->word)<0)
				{	
					prev = curr;
					curr = curr->next;
				}
				node->next = curr;
				prev->next = node;
			}
			//swap(root, prev, ptr);
			root = root->next;
	}
	return organizer;
}

void swap(Node* root, Node* *a, Node* b)
{	
	
	Node* tmp;
	tmp = malloc ( sizeof* root);
	Node* prev =root;
	while(prev != NULL)
	{
		prev = prev->next;
	} 
	tmp->next = b->next;
	//strcpy(tmp->word, a->word);
	b->next = tmp;
	prev->next = b;
	free(tmp);
	
	
	//char* nemo = (char*) malloc(20*sizeof(char));
	//Node* temp;
	//temp = malloc ( sizeof *temp->next );
	//strcpy(a->word, temp->word);
	//strcpy(b->word, a->word);
	//strcpy(temp->word, b->word);
	//free(temp->next);
}

//inspired by some ideas from prev comparch assignment -
//generates a LL in each address of the hashtable
//each token/node is populated with a word
Node* tokenize(char* string)
{
	Node* root = NULL;
	Node* ptr = NULL;
	//char alphabet[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	int i, start, end, size;
	for (i=0; i<strlen(string); i++)
	{
		start = i;
		while(!isalpha(string[i]))
		{
			start++;
			i++;
		}
		end = start+1;
		while(isalpha(string[end]))
		{
			i++;
			end++;
		}
		size = end-start+1;
		char temp[size];
		memcpy(temp, string+start, size);
		temp[size-1] = '\0';
		Node* curr = addStringNode(temp);
		if(root == NULL)
		{
			root = curr;
			ptr = root;
		}
		//add on to existing list otherwise
		else
		{
			ptr->next = curr;
			ptr = ptr->next;
		}
		//add(root, alphabet[])
	}
	return root;
}

int checkIfAlpha(char* string[])
{
	if(isalpha)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Add function for LinkedList
Node* add (Node*head, char word[])
{
  Node*current = NULL;
 
  if ( head == NULL ) {
    head = malloc ( sizeof *head );       
    head->next = NULL;
  }
  else {
    current = malloc ( sizeof *current->next );
    current->next = head;
    head = current;
  }
 
  strcpy ( head->word, word );
  return head;
}
 
void print (Node*head)
{
  while ( head != NULL ) {
    printf ( "\n%s ", head->word );
    head = head->next;
  }
  printf ( "\n" );
}

int main(int argc, char** argv)
{
	char* charList = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	//error cases for exit
	if(argc!=2) //|| strlen(argv[1]) == 0 || !strpbrk(argv[1], alphabet))
 	{
 		printf("incorrect usage\n");
 		return 1;	
 	}
 	if (strlen(argv[1]) == 0)
 	{
		printf("incorrect usage\n");
 		return 1;
 	}
 	if (!strpbrk(argv[1], charList))
 	{
		printf("incorrect usage\n");
 		return 1;
 	}
 	
	char* inputString = argv[1];
	Node* root = tokenize(inputString);		
	hashTable* organizer = sorter(root);
	int i;
	Node* token;
	//52 is twice size of alphabet, including capitalized chars
	for (i=0; i<52; i++) //for (i=0; i<strlen(inputString+1); i++)
	{
		token = organizer->table[i];
		while(token!=NULL)
		{
			printf("%s\n", token->word);
			token = token->next;
		}
	}
	
	//free table
	int j;
	Node* ptr;
	Node* temp;
	for (j=0; j< strlen(inputString); j++)
	{
		ptr = organizer->table[j];
		while(ptr!=NULL)
		{
			temp = ptr->next;
			free(ptr->word);
			free(ptr);
			ptr = temp;
		}
	}
	free(organizer->table);
	free(organizer);
	
	//free list
	Node* tmp;
	while(root!=NULL)
	{
		tmp = root->next;
		free(root->word);
		free(root);
		root = tmp;
	}
	return 0;
}

/*
//Add function for LinkedList
Node* add (Node*head, char word[])
{
  Node*current = NULL;
 
  if ( head == NULL ) {
    head = malloc ( sizeof *head );       
    head->next = NULL;
  }
  else {
    current = malloc ( sizeof *current->next );
    current->next = head;
    head = current;
  }
 
  strcpy ( head->word, word );
  return head;
}
 
void print (Node*head)
{
  while ( head != NULL ) {
    printf ( "\n%s ", head->word );
    head = head->next;
  }
  printf ( "\n" );
}
*/

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
