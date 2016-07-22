/*
* ============================================================================
*
* Author: Tatyana Vlaskin
* Course: CS 261
* Assignment 6
* Created: 11/29/2014
* File name: main.c
* Description: concordence implementation
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
*   10. http://www.chhing.org/hash-maps.html
*   11. https://github.com/robertkety/dataStructures
* ============================================================================
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;
	int tableSize = 10;
	clock_t timer;
	FILE *fileptr;
	char *word;
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.

     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input1.txt"; /*specify your input text file here*/
    printf("\n");
    printf("opening file: %s\n", filename);
	timer = clock();
	hashTable = createMap(tableSize);

    /*... concordance code goes here ...*/
	fileptr = fopen(filename, "r");
    //error msg if input file not found
    if (!fileptr){
        printf("Could not open input file\n");
    }
	//char *word;
    while ((word = getWord(fileptr))) //Read in a word with getWord().
    {
        if (containsKey(hashTable, word))//If the word is already in your hash table then
                                        // increment it's number of occurrences.
        {
            ValueType *val = atMap(hashTable, word);
            (*val)++;
            free(word);
        }
        else {
            insertMap(hashTable, word, 1); //If the word is not in your hash table then
                                            // insert it with an occurrence count of 1.
        }
    }

    printf("\n");

        //Print words with values on one line each as specified in assignment
    printf("WORDS IN THE HASH TABLE: \n");
    for (int i = 0; i < hashTable->tableSize; i++){
        hashLink *cur = hashTable->table[i];
        while (cur != 0){
            printf("%s: %d\n", cur->key, cur->value);
            cur = cur->next;
        }
    }
    fclose(fileptr);
	/*... concordance code ends here ...*/

	printMap(hashTable);
	timer = clock() - timer;
	printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));
    printf("\n");
	printf("Deleting keys\n");

	removeKey(hashTable, "and");
	removeKey(hashTable, "me");
	removeKey(hashTable, "the");

		//Print words with values on one line each as specified in the assignment
	printf("\n");
	printf("WORDS IN THE HASH TABLE AFTER SOME WORDS WERE DELETED: \n");
    for (int i = 0; i < hashTable->tableSize; i++)
    {
        hashLink *current = hashTable->table[i];
        while (current != 0){
            printf("%s: %d\n", current->key, current->value);
            current = current->next;
        }
    }

	printMap(hashTable);

	deleteMap(hashTable);
	printf("\nDeleted the table\n");
	printf("\n");
	return 0;
}
///had to change printf("Value:%d",(int *)v);
///to printf("Value:%d",v); because of warning on the FLIP
void printValue(ValueType v) {
    printf("Value:%d",v);
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = malloc(sizeof(char) * maxLength);
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
		   character == 39) /*or is an apostrophy*/
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
