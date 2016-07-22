#ifndef ArrayBagStack
#define ArrayBagStack

#define TYPE int
#define EQ(a,b) (a=b)

struct arrayBagStack{
	TYPE data[100];
	int count;
};

void initArray(struct arrayBagStack *b);
void addArray(struct arrayBagStack *b, TYPE v);
int containsArray(struct arrayBagStack *b, TYPE v);
void removeArray(struct arrayBagStack *b, TYPE v);
int sizeArray(struct arrayBagStack *b);

void pushArray(struct arrayBagStack *b, TYPE v);
TYPE topArray(struct arrayBagStack *b);
void popArray(struct arrayBagStack *b);
int isEmptyArray(struct arrayBagStack *b);

#endif

#include <stdio.h>
#include <stdlib.h>

void printArray(struct arrayBagStack *b);


int main(void) {
	struct arrayBagStack *b = malloc(sizeof(struct arrayBagStack));
	printf("Array should be empty:\n");
	initArray(b);
	printArray(b);

	printf("Add 10, 20, and 30:\n");
	pushArray(b,10);
	pushArray(b,20);
	pushArray(b,30);
	printArray(b);

	printf("Remove 20:\n");
	removeArray(b,20);
	printArray(b);

	printf("Add 50:\n");
	pushArray(b,50);
	printArray(b);

	printf("Pop:\n");
	popArray(b);
	printArray(b);

	printf("Top:\n");
	printf("%d",topArray(b));

	free(b);
	return 0;
}

void printArray(struct arrayBagStack *b){
	int i;
	if(isEmptyArray(b)){
		printf("\tArray is empty\n");
		return;
	}
	for(i=0; i<b->count; ++i){
		printf("\t%d\n",b->data[i]);
	}
	printf("\n");
}

void initArray(struct arrayBagStack *b){
	int i;
	for(i=0; i<100; ++i){
		b->data[i]=0;
	}
	b->count=0;
}
void addArray(struct arrayBagStack *b, TYPE v){
	b->data[b->count] = v;
	++b->count;
}
int containsArray(struct arrayBagStack *b, TYPE v){
	int i;
	for(i=0;i<b->count; ++i){
		if(v==b->data[i]){
			return 1;
		}
	}
	return 0;
}
void removeArray(struct arrayBagStack *b, TYPE v){
	int i, j;
	if(containsArray(b, v)){
		for(i=0; i<b->count; ++i){
			if(v == b->data[i]){
				for(j=i; j<b->count-1; ++j){
					b->data[j] = b->data[j+1];
				}
				break;
			}
		}
		--b->count;
	}
}
int sizeArray(struct arrayBagStack *b){
	return b->count;
}

void pushArray(struct arrayBagStack *b, TYPE v){
	addArray(b,v);
}
TYPE topArray(struct arrayBagStack *b){
	if(!isEmptyArray(b)){
		return b->data[b->count-1];
	}
	return NULL;
}
void popArray(struct arrayBagStack *b){
	b->data[b->count-1] = 0;
	--b->count;
}
int isEmptyArray(struct arrayBagStack *b){
	if(0 == b->count){
		return 1;
	}
	return 0;
}
