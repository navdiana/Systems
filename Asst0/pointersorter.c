// Naeem Hossain
// Systems
// February 5, 2017
// Asst0: String Sorting

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// Simple program to sort words from a given input string: 

// NON ALPHABET CHARS

// 1) Create empty hashtable
// 2) Go through string, turn all non-alphabet chars into spaces
// 3) Read strings into program
// 4) Store strings into hash table
// 5) Sorting
// 6) Return result

/* Prototype read input method
int main(){

	FILE *f;
    char c;
    f=fopen("testcases.txt","rt");

    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }

    fclose(f);
    return 0;
}
*/

int main(int argc, char* argv[])
{
    char const* const testcases = argv[1]; /* should check that argc > 1 */
    FILE* file = fopen("testcases.txt", "r"); /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);
    return 0;
}


