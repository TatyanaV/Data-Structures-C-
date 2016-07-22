/* CS261- Assignment 1 - Q.4*/
/* Name:tatyana vlaskin
 * Date:10.11.2014
 * Program requirements:
 Consider the structure student in Q1.c. Modify the above sort(...) function from Q.3 to sort an array of n
students based on their scores in ascending order. The function prototype is void sort(struct student*
students, int n). The IDs and scores of the students are to be generated randomly (see use of rand()). You
can assume that IDs are unique
* Solution description:
SEE COMMENTS FOR SOLUTION DESCRIPTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <time.h> //Used to seed the rand function

struct student{
	int id;
	int score;
};
//sort the students by the score in acsending order
void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     int index1; //lower index
     int index2;//higher index
     int tempScore; // variable to store score if lower index # is higher than higher index #
     int tempID;// variable to store score if lower index # is higher than higher index #
     for (index1=0; index1 < (n -1); index1++){//loop through the array starting at index 0
        for(index2 = (index1+1); index2 < n; index2++){//loop through the array starting at index 1
            if (students[index1].score > students[index2].score){//if score at the lower index is lower than score at the higher index
                //swap the score and id #, similar to swapping values in program Q3.c
                tempScore= students[index1].score;
                tempID = students[index1].id;
                students[index1].score = students[index2].score;
                students[index1].id = students[index2].id;
                students[index2].score = tempScore;
                students[index2].id = tempID;
            }
        }
     }
}

/*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
void generate(struct student* students){
     int studentNumber;// keeps track of tsudents
     for(studentNumber=0; studentNumber<10; studentNumber++){ // generates 10 ID#
        students[studentNumber].id = ((rand() %10) +1); //1 and 10 are inclusive
        for(int j=0; j<=(studentNumber-1); j++){// checks and makes sure that ID# is unique
                if ( students[studentNumber].id ==  students[j].id){// if newly generated # if the matches one of the # in the array
                        studentNumber--;// the student is decremented and new number is generated in case # is a duplicate
                }
            }
     }

    for(studentNumber=0; studentNumber<10; studentNumber++){// generate score for each student
        students[studentNumber].score = (rand()%100 +1); //1 and 100 are inclusive
     }
}
//output contents of the array
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int studentNumber;// keeps track of students
        for(studentNumber=0; studentNumber<10; studentNumber++){//displays information about each student
            printf("Student # %d : ID %d Score %d \n", (studentNumber+1), students[studentNumber].id, students[studentNumber].score);
        }
}


int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student* students = (struct student*) malloc(n * sizeof(struct student));
    // Seed rand()
    srand( time(NULL) );
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    generate(students);
    /*Print the contents of the array of n students.*/
    output(students);
    /*Pass this array along with n to the sort() function*/
    sort(students,n);
    /*Print the contents of the array of n students.*/
    printf("\nSorted array of students based on their scores in the ascending order.:\n");
    output(students);
    /*Deallocate memory from stud*/
    assert (students != 0); //Check that students is not NULL (NULL == 0) before you attempt to free it.
    free(students);
    return 0;
}
