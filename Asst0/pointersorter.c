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


int main (int argc, char **argv)
{
    int c;
    char *input = argv[1];
    FILE *input_file;

    input_file = fopen(testcases.txt, "r");

    if (input_file == 0)
    {
        //fopen returns 0, the NULL pointer, on failure
        perror("Canot open input file\n");
        exit(-1);
    }
    else
    {
        int found_word = 0;

        while ((c =fgetc(input_file)) != EOF )
        {
            //if it's an alpha, convert it to lower case
            if (isalpha(c))
            {
                found_word = 1;
                c = tolower(c);
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

    return 0;
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
