/* CS261- Assignment 2 - calc.c*/
/* Name: Holly Harmon	
 * Date: 04/20/2014
 * Solution description: Takes commandline input from the user to that uses a "stack" to complete
 * calculations using Reverse Polish Notation.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double num2 = topDynArr(stack);
	popDynArr(stack);
	double answer = num1 + num2;
	pushDynArr(stack, answer);
	/* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double num2 = topDynArr(stack);
	popDynArr(stack);
	double answer = num2 - num1;
	pushDynArr(stack, answer);
	
	/* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double num2 = topDynArr(stack);
	popDynArr(stack);
	double answer = num2 / num1;
	pushDynArr(stack, answer);
	
	/* FIXME: You will write this function */
}

void multiply(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double num2 = topDynArr(stack);
	popDynArr(stack);
	double answer = num2 * num1;
	pushDynArr(stack, answer);
}

void power(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double num2 = topDynArr(stack);
	popDynArr(stack);
	double answer = pow(num2, num1);
	pushDynArr(stack, answer);
}

void square(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = num1 * num1;
	pushDynArr(stack, answer);
}

void cube(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = num1 * num1 * num1;
	pushDynArr(stack, answer);
}

void absoluteValue(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = fabs(num1);
	pushDynArr(stack, answer);
}

void squareRoot(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = sqrt(num1);
	pushDynArr(stack, answer);
}

void exponent(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = exp(num1);
	pushDynArr(stack, answer);
}

void nLog(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = log(num1);
	pushDynArr(stack, answer);
}

void logFun(struct DynArr *stack)
{
	double num1 = topDynArr(stack);
	popDynArr(stack);
	double answer = log10(num1);
	pushDynArr(stack, answer);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0) {
			if(i < 3) {
				printf("Not enough operands.\n");
				return 0;
			}
			else {
				add(stack);
			}
		}
		else if(strcmp(s,"-") == 0) {
			if(i < 3) {
				printf("Not enough operands.\n");
				return 0;
			}
			else {
				subtract(stack);
			}
		}
		else if(strcmp(s, "/") == 0) {
			if(i < 3) {
				printf("Not enough operands.\n");
				return 0;
			}
			else {
				divide(stack);
			}
		}
		else if(strcmp(s, "x") == 0) {
			if(i < 3) {
				printf("Not enough operands.\n");
				return 0;
			}
			else {
				multiply(stack);
			}
			/* FIXME: replace printf with your own function */
		}
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			square(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absoluteValue(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponent(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			nLog(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			logFun(stack);
		else 
		{
			//There was a note on Piazza saying we should just enter the pi and e
			//numbers to two decimal points.
			if(strcmp(s, "e") == 0) {
				pushDynArr(stack, 2.71);
			}	
			else if(strcmp(s, "pi") == 0) {
				pushDynArr(stack, 3.14);  
			}
			else if(isNumber(s, &result) == 0) {
				printf("Input is neither an operand or operator.\n");
				return 0;
			}
			else if(isNumber(s, &result) == 1){
				pushDynArr(stack, result);
			}
		
		
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	
	result = topDynArr(stack);
	printf("Result: %f\n", result);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1) {
		printf("Enter an equation in the command line.\n");
		return 0;
	}

	calculate(argc,argv);
	return 0;
}

