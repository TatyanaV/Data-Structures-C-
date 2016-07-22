/*
* ============================================================================
*
* Author: Tatyana Vlaskin
* Course: CS 261
* Assignment 6
* Created: 11/29/2014
* File name: hashMap.c
* Description: hash map implementation
* References:
*   1. Lecture notes
*   2. Worksheet 38 -- a lot of functions taken from the answerkey of this worksheet
*   3. https://d1b10bmlvqabco.cloudfront.net/attach/i08em866vyx49w/htdjz5672h1ex/i2ocpqvllwnb/Worksheet38.links.ans.pdf
*   4. Piazza discussion boad
*   5. Chapter 12
*   6. recitation_file_operations.ppt
*   7. http://katiemusick.weebly.com/hash-tables.html
*   8. https://github.com/davidmerrick/Classes/blob/master/CS%20261/Assn%206/spellcheck.c
*   9. https://github.com/baylesj/cs261/blob/master/6/challenge/main.c
*   10. http://www.chhing.org/hash-maps.html
*   11. https://github.com/robertkety/dataStructures
*   12. https://github.com/shawnharmsen/CS261/tree/master/Assignment%206/In%20Progress
* ============================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

////////////////////////////////////////////////////////////////////////////////////
//function to find key index using either stringHash1 or stringHash2
//this function was not in the assignment
//however, the requirement of the assignment state that
//Your code should check this value to determine
//which hashing function to use. HASHING_FUNCTION==1 means use
//stringHash1 and HASHING_FUNCTION==2 means use stringHash2.
/*
 this is useful for you in answering the questions. if your write your code such
 that you call stringHash1 when HASHING_FUNCTION==1 and stringHash2 when
 HASHING_FUNCTION==2 then you only need to change this value in order to switch
 hashing functions that your code uses. you are not required to use this value
 though.
 */
int _findKey (struct hashMap *hash, KeyType str){
    assert (hash != NULL);
    int index;
    if (HASHING_FUNCTION == 1)
        index = stringHash1(str) % hash->tableSize; //http://stackoverflow.com/questions/1504420/c-what-does-the-percentage-sign-mean
    else if (HASHING_FUNCTION == 2)
        index = stringHash2(str) % hash->tableSize;
    if (index < 0)
        index += hash->tableSize;
    return (index);
}

//////////////////////////////////////////////////////////////////////////////////////

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	/*write this*/
    assert (ht != 0);
    hashLink *current;
    hashLink *next;
    for(int i = 0; i < ht->tableSize; i++) {
        current = ht->table[i];
        while(current != 0) {
            next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
        free(ht->table);
        ht->tableSize = 0;
        ht->count = 0;
    }
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/
    int i;
    hashLink **oldTable = ht->table;
    ht->table = (hashLink**)malloc(newTableSize * sizeof(hashLink*));
    int oldts = ht->tableSize;
    ht->tableSize = newTableSize;
    ht->count = 0;
    for(i=0; i < ht->tableSize; i++) {
        ht->table[i] = NULL;
    }
    for(i=0; i < oldts; i++){
        hashLink *cur = oldTable[i];
        hashLink *next;
        while(cur != NULL){
            insertMap(ht, cur->key, cur->value);
            next = cur;
            cur = cur->next;
            free (next);
        }
    }
    free(oldTable);
}


/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v){
	/*write this*/
    assert (ht != 0);
    if (containsKey(ht, k))
    ht->table[_findKey(ht, k)]->value = v;
    else {
        struct hashLink *newLink = malloc(sizeof(struct hashLink));
        newLink->value = v;
        newLink->key = k;
        newLink->next = ht->table[_findKey(ht, k)];
        ht->table[_findKey(ht, k)] = newLink;
        ht->count++;
    }
    if (tableLoad(ht) > LOAD_FACTOR_THRESHOLD)
    _setTableSize(ht, ht->tableSize * 2);
}
/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
	/*write this*/
	assert (ht != 0);
    struct hashLink *ptr = ht->table[_findKey(ht, k)];
    while (ptr != 0){
        if (strcmp(ptr->key,k) == 0)
            return(&(ptr->value));
            ptr = ptr->next;
    }
    return 0;
}
/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
	assert (ht != NULL);
    struct hashLink *ptr = ht->table[_findKey(ht, k)];
    while (ptr != 0){
        if (strcmp(ptr->key,k) == 0)
            return 1;
            ptr = ptr->next;
    }
    return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	/*write this*/
	assert (ht != NULL);
    struct hashLink *cur = ht->table[_findKey(ht, k)];
    while (cur != 0){
        if (strcmp(cur->key, k) == 0 ){
            struct hashLink *temp = cur->next;
            free (cur->key);
            free (cur);
            ht->table[_findKey( ht, k ) ] = temp;
            ht->count--;
            return;
        }
        while (cur->next != NULL ){
            if (strcmp(cur->next->key, k) == 0){
                struct hashLink *temp = cur->next->next;
                free(cur->next->key);
                free(cur->next);
                cur->next = temp;
                ht->count--;
                return;
            }
            cur = cur->next;
        }
    }
}
/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
	assert (ht != NULL);
    return (ht->count);
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
	assert (ht != NULL);
    return (ht->tableSize);
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	/*write this*/
	assert (ht != NULL);
    int count = 0;
    for (int i = 0; i < ht->tableSize; ++i)
        if (ht->table[i] == NULL)
            count++;
    return (count);
}
/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	/*write this*/
	assert (ht != NULL);
    return ((ht->count) / (double)(ht->tableSize));
}

void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}


