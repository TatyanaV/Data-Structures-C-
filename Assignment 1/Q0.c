/* CS261- Assignment 1 - Q. 0*/
/* Name: Tatyana Vlaskin
 * Date: 10/11/2014
 * Solution description:
In the main function, declare an integer, x.
Print the address of x (using the address of operator).
Pass x as an argument to a function void fooA(int* iptr).
In fooA(int * iptr), print the value of the integer pointed to
by iptr, the address pointed to by iptr, and
the address of iptr itself.
In the main function, following the call to fooA(...), print the value of x.
 */

#include <stdio.h>
#include <stdlib.h>
//displays the value printed by the pointer, the adress of the value and the address of the pointer
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value pointed to by iptr*: %d \n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr*: %p \n", iptr);//address is expressed as a hexadecimal
     printf("The address pointed to by iptr*: %d \n", iptr);//address is expressed as a decimal
     /*Print the address of iptr itself*/
     printf("The address of iptr itself: %p \n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 0; // i decided to initialize it to 0
    /*print the address of x*/
    printf("The address of x: %p \n", &x);;//address is expressed as a hexadecimal
    printf("The address of x: %d \n", &x);//address is expressed as a decimal
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x: %d \n",x);
    return 0;
}

