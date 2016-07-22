//tatyana vlaskin
//Programming Assignment #3
//Problem 1: Deque and bag implementation
//10/26/2014

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

//I took this function from the worksheet 19
void _initList (struct linkedList *lst) {
    /* FIXME: you must write this */
    //assert(lst != 0);
    //Init size, first and last links
    lst->firstLink = malloc(sizeof(struct DLink));
    assert(lst->firstLink != 0); // asert that the 1st link was created properly
    lst->lastLink =  malloc(sizeof(struct DLink));
    assert(lst->lastLink != 0); //Assert that the last link was created properly
    //Connect Sentinals - NOTE: Do not make circularly linked list
    lst->firstLink->next = lst->lastLink;
    lst->lastLink->prev = lst->firstLink;
    lst->size = 0; // initilize size to 0
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList(){
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

//this function was taken from the worksheet 19
void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v){
    /* FIXME: you must write this */
    assert(lst != 0);
    assert(l != 0);
    //Create new link and assert it was created successfully
    struct DLink* newLink = (struct DLink *) malloc(sizeof(struct DLink));
    assert(newLink != 0);
    //Update value with v, next and prev for newLink
    newLink->value = v;
    newLink->next = l;
    newLink->prev = l->prev;
    //Insert link into list before l
    l->prev->next = newLink;
    l->prev = newLink;
    //Increase lst->size
    lst->size++;
}

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
//function is taken from worksheet 19
void addFrontList(struct linkedList *lst, TYPE e){

	/* FIXME: you must write this */
	_addLinkBefore(lst, lst->firstLink->next, e);

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
//function is taken from worksheet 19
void addBackList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
	_addLinkBefore(lst, lst->lastLink->next, e);
}


/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
		/* FIXME: you must write this */
    assert(lst != 0);
    assert(lst->size != 0);
    //assert(!LinkedListIsEmpty(lst));
	/*temporary return value...you may need to change this */
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst){
	/* FIXME: you must write this */
		/* FIXME: you must write this */
    assert(lst != 0);
    assert(lst->size != 0);
    //assert(!LinkedListIsEmpty(lst));
    /*temporary return value...you may need to change this */
    return(lst->lastLink->prev->value);

}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l){
    /* FIXME: you must write this */
    assert(lst != 0);
    assert(l != 0);
    //Adjust the next and prev links of l to remove l
    l->prev->next = l->next;
    l->next->prev = l->prev;
    //Reduce lst->size
    lst->size--;
    //Free l from memory
    free(l);
}
/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
    /* FIXME: you must write this */
    assert(lst != 0);
    assert(lst->size != 0);
   // assert(! linkedListIsEmpty(lst));
    //Remove lst->firstLink->next
    _removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
    /* FIXME: you must write this */
    assert(lst != 0);
    assert(lst->size != 0);
    // assert(! linkedListIsEmpty(lst));
    //Remove lst->lastLink->prev
    _removeLink(lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	//return(1);
	return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst){
    /* FIXME: you must write this */
    assert(lst != 0);
    //Initialize a temporary link and make it equal to first Link
    struct DLink* tempLink = (struct DLink *) malloc(sizeof(struct DLink));
    tempLink = lst->firstLink;
    //Interate through the list printing the values as you go
    while(tempLink->next != lst->lastLink){
        tempLink = tempLink->next;
        printf("%d\n", tempLink->value);
    }
    //Free the tempLink
    free(tempLink);
}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
 //function is taken from worksheet 22
void addList(struct linkedList *lst, TYPE v){
		/* FIXME: you must write this */
    assert(lst != 0);
    //Add to the top of the list
    _addLinkBefore(lst, lst->firstLink->next, v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
//function taken from worksheet 22
int containsList (struct linkedList *lst, TYPE e) {
    /* FIXME: you must write this */
	/*temporary return value...you may need to change this */
    struct DLink *current; //declare a structure
    assert(!isEmptyList(lst)); //check and make sure that there are elements in the list
    current = lst->firstLink->next; // Initialize current
    while(current!= lst->lastLink){//continue until we reach the end
        if(EQ(current->value, e)) //if current matches the value
            return 1;
        current=current->next;
    }
    return 0;
}


/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
    struct DLink *current;
    assert(!isEmptyList(lst));// make sure that the list is not empty
    current = lst->firstLink->next; // Initialize current
    while(current!= lst->lastLink) {// loop until the end is reached
        if(EQ(current->value,e)) { // if there passed paremeter matches one of the elements in the list
            _removeLink(lst,current);// remove the element, this function was writen in earlier lessons
            break; // Only one copy of element will be removed
        }
        current=current->next;// set current to the next element
    }
}
