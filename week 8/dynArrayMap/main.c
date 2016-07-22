#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"

/* For using the priority queue interface*/
#define TASK_DESC_SIZE 128

struct Task {
	char description[TASK_DESC_SIZE];  	/* description of the task */
	int priority;			  			/* task priority */
};

typedef struct Task Task;

/*  Compare two keys

    param:  left    first key
    param:  right 	second key
    pre:    none
    post:   none
	ret: 	-1 if priority of leftkey < rightkey
			1 if priority of leftkey > rightkey
			0 if priority of leftkey = rightkey
*/

int compareM (TYPE l, TYPE r){
	char *lkey, *rkey;

	lkey = (char *) l;
	rkey = (char *) r;

	if(strcmp(lkey,rkey)== 0)
		return 0;
	if(strcmp(lkey,rkey) < 0)
		return -1;
	else return 1;
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
int compareH(TYPE left, TYPE right)
{
	struct Task *myL, *myR;
	myL = (struct Task *)left;
	myR = (struct Task *)right;

	if (myL->priority < myR->priority)
		return -1;
	else if (myL->priority > myR->priority)
		return 1;
	else
		return 0;
}


/*  Compare two ints

    param:  left    first int
    param:  right 	second int
    pre:    none
    post:   none
	ret: 	-1 if priority of left < right
			1 if priority of left > right
			0 if priority of left = right
*/
int compareB(TYPE l, TYPE r){
	int *myL, *myR;
	myL = (int*)l;
	myR = (int*)r;

	if(*myL == *myR)
		return 0;
	if(*myL < *myR)
		return -1;
	else return 1;
}

/* Function to create a task when using the priority queue interface*/
TYPE createTask (int priority, char *desc)
{
	struct Task *newTask;
	newTask = malloc(sizeof(struct Task));
	newTask->priority = priority;
	strcpy(newTask->description, desc);
	return newTask;
}

#define TESTSORT
int main(int argc, const char * argv[])
{

#ifdef TESTBAG
	 DynArr *myBag;
	 int val1, val2;
	 val1 = 1;
	 val2 = 2;

	 myBag =  createDynArr(10);

	 addDynArr(myBag, &val1);
	 addDynArr(myBag, &val2);
	 removeDynArr(myBag, &val2, compareB);

		int res = containsDynArr(myBag,&val1, compareB);

		if(res > 0)
			printf("Contained 1 \n");
		else printf("Did not contain 1\n");

		res = containsDynArr(myBag, &val2, compareB);

		if(res > 0)
			printf("Contained 3\n");
		else printf("Did not contain 3\n");
		deleteDynArr(myBag);
#endif



#ifdef TESTMAP
	DynArr *mainList;
	mainList = createDynArr(10);
	
	int val1 = 1;
	int val2 = 2;
	putMap(mainList,"joe", &val1, compareM);
	putMap(mainList, "Jane", &val2, compareM);
//	removeMap(mainList, "joe", compareM);
	int *testVal = (int *)getMap(mainList, "Jane", compareM);
	printf("Value for Jane = %d\n", *testVal);
	if(containsMap(mainList, "joe", compareM))
		printf("Contained joe\n");
	if(containsMap(mainList, "Jane", compareM))
		printf("Contained Jane\n");
	deleteDynArr(mainList);
#endif


#ifdef TESTHEAP
	TYPE tasks[10];

	DynArr *mainList;
	mainList = createDynArr(10);

	/* create tasks */
	tasks[0] = createTask(9, "task 1");
	tasks[1] = createTask(3, "task 2");
	tasks[2] = createTask(2, "task 3");
	tasks[3] = createTask(4, "task 4");
	tasks[4] = createTask(5, "task 5");
	tasks[5] = createTask(7, "task 6");
	tasks[6] = createTask(8, "task 7");
	tasks[7] = createTask(6, "task 8");
	tasks[8] = createTask(1, "task 9");
	tasks[9] = createTask(0, "task 10");

	/* add tasks to the dynamic array as a heap */
	addHeap(mainList, tasks[0],compareH);
	addHeap(mainList, tasks[1],compareH);
	addHeap(mainList, tasks[2],compareH);
	addHeap(mainList, tasks[3],compareH);
	addHeap(mainList, tasks[4],compareH);
	addHeap(mainList, tasks[5],compareH);
	addHeap(mainList, tasks[6],compareH);
	addHeap(mainList, tasks[7],compareH);
	addHeap(mainList, tasks[8],compareH);
	addHeap(mainList, tasks[9],compareH);

	for(int i = 0; i < sizeDynArr(mainList);i++)
		printf("DynArr[%d] = %d\n", i, ((struct Task *)getDynArr(mainList,i))->priority);


	while(!isEmptyDynArr(mainList))
	{
		struct Task *v;
		v = (struct Task*) getMinHeap(mainList);
		printf("Val = %s ___%d\n", v->description, v->priority);
		removeMinHeap(mainList,compareH);
	}
	deleteDynArr(mainList);
#endif

#ifdef TESTSORT
	TYPE tasks[10];
	DynArr *mainList;
	mainList = createDynArr(10);

		/* create tasks */
	/* create tasks */
	tasks[0] = createTask(9, "task 1");
	tasks[1] = createTask(3, "task 2");
	tasks[2] = createTask(2, "task 3");
	tasks[3] = createTask(4, "task 4");
	tasks[4] = createTask(5, "task 5");
	tasks[5] = createTask(7, "task 6");
	tasks[6] = createTask(8, "task 7");
	tasks[7] = createTask(6, "task 8");
	tasks[8] = createTask(1, "task 9");
	tasks[9] = createTask(0, "task 10");

	/* add tasks to the dynamic array */
	addDynArr(mainList, tasks[0]);
	addDynArr(mainList, tasks[1]);
	addDynArr(mainList, tasks[2]);
	addDynArr(mainList, tasks[3]);
	addDynArr(mainList, tasks[4]);
	addDynArr(mainList, tasks[5]);
	addDynArr(mainList, tasks[6]);
	addDynArr(mainList, tasks[7]);
	addDynArr(mainList, tasks[8]);
	addDynArr(mainList, tasks[9]);

	printf("Before Sort Called \n");
	for(int i = 0; i < sizeDynArr(mainList);i++)
			printf("DynArr[%d] = %d\n", i, ((struct Task*)getDynArr(mainList,i))->priority);


	/* sort tasks */
	sortHeap(mainList,compareH);
	printf("After Sort Called \n");

	/* print sorted tasks from the dynamic array */
	for(int i = 0; i < sizeDynArr(mainList);i++)
				printf("DynArr[%d] = %d\n", i, ((struct Task*)getDynArr(mainList,i))->priority);

	deleteDynArr(mainList);
#endif
	return 0;
}
