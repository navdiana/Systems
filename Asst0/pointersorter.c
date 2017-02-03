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
//char c; //global var


struct node{

    char name[20];
    int id;
    struct node *next;

}*head;



int main(void){

    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->next = NULL;
    head = temp;

    FILE *ifp;
    ifp = fopen("testcases.txt", "r");

    int c = 0;

    char buffer[1024];
    memset(buffer, 0, 1024);
    while(c<5){
        fgets(buffer, 1024, ifp);
        sscanf(buffer, "%19[^,], %d", temp->name, &temp->id);
        printf("%d %s %d\n",c, temp->name, temp->id);
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->next = NULL;
        c++;
    }
}

/*
int main(int argc, char* argv[])
{
    char const* const testcases = argv[1]; // should check that argc > 1 
    FILE* file = fopen("testcases.txt", "r"); // should check the result 
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        // note that fgets don't strip the terminating \n, checking its
        // presence would allow to handle lines longer that sizeof(line) 
        printf("%s\n", line); 
    }
    //may check feof here to make a difference between eof and io failure -- network
    //timeout for instance 

    fclose(file);
    return 0;
}
*/

/*
int main()
{
	// Creating a pointer file type
	FILE *ptr;
	char array[255];
	int id;
	int i;
	//EOF = "END_OF_FILE"
	
	// Opening a file for reading data
	ptr = fopen("testcases.txt", "r");
	
	for(i = 0; i <= EOF; i++)
	{
		// Reading data from the file
		fscanf(ptr, "%s", array); 
	
		// Concerting string to integer using "atoi" function
		id = atoi(array);
	
		// Check if id is 2
		if (id == 4) 
		{
			fgets(array, 255, (FILE*)ptr); //used to read the whole line
			printf("%s", array);
			break; //while condition match then terminate loop
		}
	}
	return 0;
}
*/
