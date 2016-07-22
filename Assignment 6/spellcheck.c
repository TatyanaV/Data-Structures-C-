/*
* ============================================================================
*
* Author: Tatyana Vlaskin
* Course: CS 261
* Assignment 6
* Created: 11/29/2014
* File name: spellcheck.c
* Description: spell check implementation
* References:
*   1. Lecture notes
*   2. Worksheet 38
*   3. https://d1b10bmlvqabco.cloudfront.net/attach/i08em866vyx49w/htdjz5672h1ex/i2ocpqvllwnb/Worksheet38.links.ans.pdf
*   4. Piazza discussion boad
*   5. Chapter 12
*   6. recitation_file_operations.ppt
*   7. http://katiemusick.weebly.com/hash-tables.html
*   8. https://github.com/davidmerrick/Classes/blob/master/CS%20261/Assn%206/spellcheck.c
*   9. https://github.com/baylesj/cs261/blob/master/6/challenge/main.c
*
* ============================================================================
*/


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.

 when there are no more words in the input file this function will return NULL.

 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht);

// need this function because its used in the printMap function
//in the hashMap.c
//copied and pasted from the main.c of Assignment 6
///had to change printf("Value:%d",(int *)v);
///to printf("Value:%d",v); because of warning to the FLIP
void printValue(ValueType v) {
    printf("Value:%d",v);
}


int main (int argc, const char * argv[]) {
  clock_t timer;
  struct hashMap* hashTable;
  int tableSize = 1000;
  timer = clock();
  hashTable = createMap(tableSize); // hash table is initialized
  //_initMap(hashTable,tableSize);/// this was changed from initMap(hashTable,tableSize); to _initMap(hashTable,tableSize);

  FILE* dictionary;
  dictionary = fopen("dictionary.txt", "r"); // need to open a dictionary
    //error msg if input file not found
    if (!dictionary){
        printf("Could not open dictionary file\n");
    }

  loadDictionary(dictionary,hashTable); //dictionary is loaded in the hash table
  timer = clock() - timer;
  printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);

  char* word = (char*)malloc(256*sizeof(char));
  int quit=0;
  //continue to prompt for words to be checked the spelling
  while(!quit){
    printf("Enter a word in LOWCASE LETTERS to check if its in the dictionary. ");
    printf("\n");
    printf("Type quit if you want to exit the program. ");
    printf("\n");
    printf("Enter a word: ");
    scanf("%s",word);
    /*
      ... spell checker code goes here ...
      ... You write this               ...
    */
    if(containsKey(hashTable, word)){ // if the word is in the hash table = dictionary
        printf("That is spelled CORRECTLY!\n");
        printf("\n");
    }
    else{
        printf("Spelling ERROR!\n"); // if the word is not in the dictionary
        printf("\n");
    }

    /* Don't remove this. It is used for grading*/
    if(strcmp(word,"quit")==0)
      quit=!quit;
  }
  free(word);

  return 0;
}

void loadDictionary(FILE* file, struct hashMap* ht){
  /* You will write this*/
    //loop to the end and getWord, occurrence 1
    while (!feof(file)) {
        char *word = getWord(file);
        if (word){
            insertMap(ht, word, 1);
        }
    }
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   (character == 39)) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}

	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
