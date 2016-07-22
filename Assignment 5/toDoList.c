/*
* ============================================================================
*
* Author: Tatyana Vlaskin
* Course: CS 261
* Assignment 5
* Created: 11/23/2014
* File name: toDoList.c
* Description: Dynamic array heap implementation
* References:
*   1. Lecture on Heap Implementation
*   2. Worksheet 33
*   3. https://github.com/baylesj/cs261/blob/master/5/turn-in/dynamicArray.c
*   4. Piazza discussion board----Xinchen Wang and Christopher Kryaninko
*
* ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};

struct bag
{
	struct DynArr *dynArr;
};


/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
Task* createTask (int priority, char *desc)
{
		/* FIXME */

    Task *newTask = malloc(sizeof(Task));
    assert(newTask != 0);
    newTask->priority = priority;
    strcpy(newTask->description, desc);
    printf("description: %s\n  priority: %d\n", newTask->description, newTask->priority);
    return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the
			task priority, followed by a tab character (\t), and
			the task description.

			The tasks are not necessarily stored in the file in
			priority order.

*/
void saveList(DynArr *heap, FILE *filePtr)
{
	int i;
	Task* task;
	assert(sizeDynArr(heap) > 0);
	for(i = 0; i < sizeDynArr(heap); i++)
	{
		task = getDynArr(heap, i);
		fprintf(filePtr, "%d\t%s\n", task->priority, task->description);
	}
}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file
*/
void loadList(DynArr *heap, FILE *filePtr)
{
	Task* task;
	char line[100];  /* Assume lines < 100 */
	char desc[TASK_DESC_SIZE];//, *nlptr;
	int priority;

	/* Read the priority first, then the description.
	 * fgets() is used to read string with spaces
	 */
#ifdef NOTDEF
    char *nlptr;
	while (fscanf(filePtr, "%d\t", &priority) != EOF)
	{
	  /* fgets() stops reading at \n character */
		fgets(desc, sizeof(desc), filePtr);
		/* remove trailing newline character */
		nlptr = strchr(desc, '\n');
		if (nlptr)
		  *nlptr = '\0';

	   	task = createTask(priority, desc);
		addHeap(heap, task);
	}
#endif

	while(fgets(line, sizeof(line), filePtr) != 0)
	{
	  sscanf(line, "%d\t%[^\n]", &priority, desc);
	  task = createTask(priority, desc);
	  addHeap(heap, task);
	} /* should use feof to make sure it found eof and not error*/

}

/*  Print the list

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{
    /* FIXME: Write this */
    struct DynArr *toPrint = createDynArr(sizeDynArr(heap));
    copyDynArr(heap, toPrint);
    int i, max = sizeDynArr(toPrint);
    sortHeap(toPrint);
    // call print_type() on each node
    for(i = 0; i < max; i++)
        print_type(getDynArr(toPrint, i));
        deleteList(toPrint);
}

/*  Delete the list

    param:  heap    pointer to the list
    post:   The tasks from the list are removed and their occupied memories are freed

*/
void deleteList(DynArr *heap)
{

	Task* task;
	while(sizeDynArr(heap) > 0)
	{
	  	/* get the task */
		task = getMinHeap(heap);
		/* remove the task */
		removeMinHeap(heap);
		/* free the task */
		free(task);
	}
	/* free the heap */
	deleteDynArr(heap);
}

/*  Compare two tasks by priority

    param:  left    first task
    param:  right 	second task
    pre:    none
    post:   none
	ret: 	-1 if priority of left < priority of right
			1 if priority of left > priority of right
			0 if priority of left = priority of right
*/
/*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in dynamicArray.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct Task*), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
    struct Task *l = (struct Task*)left;
    struct Task *r = (struct Task*)right;
    if(l->priority > r->priority){
         return 1;
    }
    else if(l->priority < r->priority){
         return -1;
    }
    else return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{

	Task* data1;
	data1 = (Task*)curval;
	printf("%d\t%s\n", data1->priority, data1->description);
}

