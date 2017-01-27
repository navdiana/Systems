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

int main(){

	FILE *f;
    char c;s
    f=fopen("testcases.txt","rt");

    while((c=fgetc(f))!=EOF){
        printf("%c",c);
    }

    fclose(f);
    return 0;
}

