#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*
* ============================================================================
*
* Author: tatyana vlaskin
* Company: Oregon State University
* Created: 11.09.2014
*
* Description:  Implementation of the binary search tree data structure
* File: compare.c
* refference:
http://stackoverflow.com/questions/13633962/adding-nodes-to-binary-search-tree
https://d1b10bmlvqabco.cloudfront.net/attach/hrboae94yo82ws/h7rv0ljgrbbfn/hux1hmtv5vx7/Worksheet29.ans.pdf
https://github.com/baylesj/cs261/blob/master/4/bst.c
https://github.com/davidmerrick/Classes/blob/master/CS%20261/Assn%204/bst.c
http://pastie.org/pastes/2832860

* ============================================================================
*/

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
	//make sure not null
    assert(left != 0);
    assert(right != 0);
    struct data *left2 = (struct data *)left; // pointer to the left value
    struct data *right2= (struct data *)right;// pointer to the right value
    if (left2->number < right2->number){ //if left is less than
        return -1;
    }
    else if (left2->number > right2->number){ // if left is greater than
        return 1;
    }
    return 0;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(TYPE curval)
{
    /*FIXME: write this*/
    assert(curval != 0);
    struct data *cur = (struct data *)curval;  //type cast void * curval to struct data cur
    printf("%d ", cur->number); // print current value

}


