/* CS261- Assignment 1 - Q.2*/
/* Name:tatyana vlaskin
 * Date:10.11.2014
 * Solution description:
 Write a function int foo(int* a, int *b, int c) which should perform the following computations
1. Set the value of a to twice its original value.
2. Set the value of b to half of its original value.
3. Assign a + b to c.
4. Return the value of c
1.
In the main function, declare three integers x,y, and z, and assign them values 5, 6, and 7
respectively. Print the values of x,y, and z. Call foo(...) appropriately passing x,y, and z as
arguments and print the returned value. After the function call, print out the values of x,y, and z
again. Answer the following question in a comment at the bottom of the file: Is the return value
different than the value of z? Why?

see comments for the solution description
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2*(*a);// dereference operator to get the value stored at the adress pointed by the pointer a
    /*Set b to half its original value*/
    *b = (*b)/2;
    /*Assign a+b to c*/
    c =((*a) + (*b));
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("x: %d \n", x);
    printf("y: %d \n", y);
    printf("z: %d \n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("The value returned by foo is: %d \n", foo(&x,&y,z));
    /*Print the values of x, y and z again*/
    printf("x: %d \n", x);
    printf("y: %d \n", y);
    printf("z: %d \n", z);

    /*Is the return value different than the value of z?  Why?*/
    //ANSWER
    //Yes the return value differs. The reason is that c is not a pointer to z.
    //As a result of this the value of z remains the same after the call of the foo.
    return 0;
}


