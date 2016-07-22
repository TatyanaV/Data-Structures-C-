#include<stdio.h>
#include<stdlib.h>
#include "avl.h"
#include "structs.h"

/* prototype for compare and printVal which are both in compare.c*/
int compare(void *left, void *right);
void printVal(void *node);

/* Example main file to begin exercising your tree */


int main(int argc, char *argv[])
{	
	struct AVLTree *tree	= newAVLTree();		
	
	/*Create value of the type of data that you want to store*/
	struct data myData1, myData2, myData3, myData4, myData5;
	
	myData1.number = 5;
	myData1.name = "rooty";
	myData2.number = 1;
	myData2.name = "lefty";
	myData3.number = 10;
	myData3.name = "righty";
	myData4.number = 30;
	myData4.name = "righty";
	myData5.number = 20;
	myData5.name  = "lefty";
	
	
	/*add the values to AVL*/
	addAVLTree(tree, &myData1, compare);
	addAVLTree(tree, &myData2, compare);
	addAVLTree(tree, &myData3,compare);
	addAVLTree(tree, &myData4, compare);
	addAVLTree(tree, &myData5, compare);
	
	printTree(tree, printVal);
	printf("\n");
	
	removeAVLTree(tree, &myData5, compare);

	printTree(tree, printVal);	
	printf("\n");
		
	return 1;
	
}
