/* CS261- Assignment 1 - Q.3*/
/* Name:tatyana vlaskin
 * Date:10.11.2014
 * Solution description:
 Write a function void sort(int* numbers, int n) to sort a given array of n integers in ascending order.
In the main function, declare an integer n and assign it a value of 20. Allocate memory for an array of
n integers using malloc. Fill this array with random numbers, using the c math library random
number generator rand(). Print the contents of the array.
1.Pass this array along with n to the sort(...) function above. Print the contents of the sorted array

SEE COMMENTS FOR SOLUTION DESCRIPTION
 */

#include <stdio.h>
#include<stdlib.h>
#include <time.h> //Used to seed the rand function

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int index1;
     int index2;
     int temp;// Variable to temporarily store number if # at the [index +1] = index2 is lower than # at the [index]=index1 position

     for (index1=0; index1 < (n -1); index1++){// loop through the array
        for(index2 = (index1+1); index2 < n; index2++){
            if (number[index1] > number[index2]){ // if # at the lower index is higher than number at the higher index
                temp= number[index1];// store # of the lower index as a temp variable
                number[index1] = number[index2];//reassign # at the higher index to be a number at the lower index
                number[index2] = temp;// assign # at the higher index to be temp (which is currectly assigned to be higher #)
            }
        }
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = (int*)malloc(n*sizeof(int));
    /*Fill this array with random numbers, using rand().*/
     /* Seed srand */
    srand( time(NULL) );// seed the rand function
    for(int index = 0; index < n; index++){// generate n random #
       array[index] = rand()%50; // i decided to generate numbers between 0 and 50
    }

    /*Print the contents of the array.*/
        for(int index = 0; index < n; index++){//loops through the array
            printf("Value at index %d:  %d \n", (index +1), array[index]);// prints # 1 at aa time
      }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the contents of the array.*/
    printf("\nSorted array:\n");
    for(int index = 0; index < n; index++){//loops through the array, which is now sorted
            printf("Value at index %d: %d \n", (index +1), array[index]);// prints # one at a time
      }


    return 0;
}
