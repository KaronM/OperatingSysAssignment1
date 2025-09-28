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
        return NULL;
    }

    char str[100];

    if (fscanf(filePtr, "%99s", str) != 1) {
        fclose(filePtr);
        return NULL;
    }

    fclose(filePtr);

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }


    char* result = malloc(length + 1);
    if (result == NULL) return NULL;

  
    for (int i = 0; i <= length; i++) {
        result[i] = str[i];
    }


    return result;
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
char* mysteryExplode(const char* str){ if (str == NULL) return NULL;

    int len = strlen(str);
    int resultLen = (len * (len + 1)) / 2;

    char* result = malloc(resultLen + 1);
    if (result == NULL) return NULL;

    int pos = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            result[pos++] = str[j];
        }
    }

    result[pos] = '\0';

    return result;
}