/* CS261- Assignment 1 - Q.1*/
/* Name: Wayne Lam
 * Date: 4/12/14
 * Solution description:

Write a function struct student* allocate() that allocates memory for ten students and returns the pointer.
 Write a function void generate(struct student* students) that generates random IDs and scores for each of the ten students and stores them in the array of students.
 You can make use of the rand() function to generate random numbers. Ensure that IDs are unique and between 1 and 10(both inclusive) and score is between 0 and 100(both inclusive).
 Write a function void output(struct student* students) that prints the ids and scores of all the students.
 Write a function void summary(struct student* students) that prints the minimum score, maximum score and average score of the ten students.
 Write a function void deallocate(struct student* stud) that frees the memory allocated to students. Check that students is not NULL (NULL == 0) before you attempt to free it
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* s = malloc(10 * sizeof(struct student));
    assert (s != 0);

     /*return the pointer*/
     return s;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int x;
     printf("ID Score \n");
     for(x=0; x<10; x++){
        students[x].id = ((rand() %10) +1);
        students[x].score = (rand()%100 +1);
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
              int x;
              for(x=0; x<10; x++){
                printf("ID%d Score%d \n", students[x].id, students[x].score);
              }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int i, sum=0, avg=0, min=100, max=0;

/*Max*/
    for(i=0; i<10; i++){
        if(students[i].score>max){
            max = students[i].score;
        }
    }

/*Min*/
      for(i=0; i<10; i++){
        if(students[i].score<min){
            min = students[i].score;
        }
    }

/*Avg*/
    for(i=0; i<10; i++){
        sum = sum + students[i].score;
    }
    avg = sum/10;

printf("The minimum score is: %d \n", min);

printf("The maximum score is: %d \n", max);

printf("The average score is: %d \n", avg);


}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
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
