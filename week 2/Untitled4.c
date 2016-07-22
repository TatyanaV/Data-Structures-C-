#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<assert.h>

struct student{
    int id;
    int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* pointer = (struct student*)malloc(10 * sizeof(struct student));
    assert (pointer != 0);

     /*return the pointer*/
     return pointer;
}


int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();



    return 0;
}

