#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */

 


char* readString(char* fileName){
    
    FILE* filePtr = fopen(fileName,"r");

    if(filePtr == NULL){
        perror("Error opening file");
    }

    char str[100];

    char* word = fscanf(&filePtr, "%s", str);
    
    fclose(filePtr);

    printf("%s",word);
    return word;
    free(str);

}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    
    if(sizeof(str)==sizeof(str[0])){
            return str;
    }

    int length = strlen(str);

    char* word_ptr;

    word_ptr = (char*)malloc(length * (length+1)/2 + 1);

    int n = sizeof(str)/sizeof(str[0]);

    for(int i = 0; i < n; i++){
        int len = i;
        for(int v = 0; v < i; v++){
            strncat(word_ptr, str[v], sizeof(word_ptr)-sizeof(str[v])-1);
        }
    }
    
    return word_ptr;

}