/* CS261- Assignment 1 - Q.1*/
/* Name: tatyana vlaskin
 * Date: 10.11.2014
 * Solution description:

Write a function struct student* allocate() that allocates memory for ten students and returns the pointer.
 Write a function void generate(struct student* students) that generates random IDs and scores for each of the ten students and stores them in the array of students.
 You can make use of the rand() function to generate random numbers. Ensure that IDs are unique and between 1 and 10(both inclusive) and score is between 0 and 100(both inclusive).
 Write a function void output(struct student* students) that prints the ids and scores of all the students.
 Write a function void summary(struct student* students) that prints the minimum score, maximum score and average score of the ten students.
 Write a function void deallocate(struct student* stud) that frees the memory allocated to students. Check that students is not NULL (NULL == 0) before you attempt to free it

For solution description, see comments.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include <time.h> //Used to seed the rand function

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* pointer = (struct student*) malloc(10 * sizeof(struct student));
    assert (pointer != 0);

     /*return the pointer*/
     return pointer;
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


void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int studentNumber;
     int sum=0;
     int average=0;
     int min=100, max=0;

/*Max*/
    for(studentNumber=0; studentNumber<10; studentNumber++){
        // max is set to 0, as we loop through the students, higher # becomes max
        if(students[studentNumber].score>max){
            max = students[studentNumber].score;
        }
    }

/*Min*/
      for(studentNumber=0; studentNumber<10; studentNumber++){
        // min is set to 100, as we loop through the students, lower # becomes min
        if(students[studentNumber].score<min){
            min = students[studentNumber].score;
        }
    }

/*Avg*/
    for(studentNumber=0; studentNumber<10; studentNumber++){
        sum = sum + students[studentNumber].score;// add all student scores
    }
    average = sum/10;// devide by the number of students to get average

printf("The minimum score is: %d \n", min);

printf("The maximum score is: %d \n", max);

printf("The average score is: %d \n", average);


}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     assert (stud != 0); //Check that students is not NULL (NULL == 0) before you attempt to free it.
     free(stud);
}

int main(){
      /* Seed rand() */
    srand( time(NULL) );
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
