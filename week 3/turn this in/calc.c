#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <math.h>
#include <assert.h>
//reference: https://github.com/jonziefle/CS261/blob/master/Assignment%202/calc.c
//tatyana vlaskin
//calc.c
//date: 10/19.2014
// if you want to add 2 numbers, enter then in the format number number -
//not number - number. Same thing is true for all operands

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
void add (struct DynArr *stack){
    if (sizeDynArr(stack) < 2){
        printf( "\n ERROR \n");
        printf("You need to have at least 2 numbers for addition \n");
        printf("Please use:  number1 number2 + format \n");
        printf("number1 + number2 will not work \n");
    }
    assert(sizeDynArr(stack) >= 2);
    double first = topDynArr(stack);
    popDynArr(stack);
    double second = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, first + second);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack){
     if (sizeDynArr(stack) < 2){
        printf( "\n ERROR \n");
        printf("You need to have at least 2 numbers for subtraction \n");
        printf("Please use:  number1 number2 - format \n");
        printf("number1 - number2 will not work \n");
    }
     assert(sizeDynArr(stack) >= 2);
    double number = topDynArr(stack);
    popDynArr(stack);
    double subtract = topDynArr(stack) - number;
    popDynArr(stack);
    pushDynArr(stack, subtract);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack){
    if (sizeDynArr(stack) < 2){
    printf( "\n ERROR \n");
    printf("You need to have at least 2 numbers for division\n");
    printf("Please use:  number1 number2 / format \n");
    printf("number1 / number2 will not work \n");
    }
    assert(sizeDynArr(stack) >= 2);
    double number = topDynArr(stack);
    popDynArr(stack);
    double divide = topDynArr(stack)/number;
    popDynArr(stack);
    pushDynArr(stack, divide);
}

/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void multiply(struct DynArr *stack){
    if (sizeDynArr(stack) < 2){
    printf( "\n ERROR \n");
    printf("You need to have at least 2 numbers for multiplication \n");
    printf("Please use:  number1 number2 x format \n");
    printf("number1 x number2 will not work \n");
    }
    assert(sizeDynArr(stack) >= 2);
    double num2 = topDynArr(stack);
    popDynArr(stack);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, num1 * num2);
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void power(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 2);
    double num2 = topDynArr(stack);
    popDynArr(stack);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, pow(num1,num2));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void squared(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, pow(num1,2));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void cubed(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, pow(num1,3));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void absoluteValue(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, fabs(num1));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void squareRoot(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, sqrt(num1));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void exponential(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, exp(num1));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void naturalLog(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, log(num1));
}
/* param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void logBase10(struct DynArr *stack){
    assert(sizeDynArr(stack) >= 1);
    double num1 = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, log10(num1));
}


double calculate(int numInputTokens, char **inputString){
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double num;
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

		if(strcmp(s, "+") == 0){
			add(stack);
			printf("Adding\n");
		}
		else if(strcmp(s,"-") == 0){
			subtract(stack);
			printf("Subtracting\n");
		}
		else if(strcmp(s, "/") == 0){
			divide(stack);
			printf("Dividing\n");
		}
		else if(strcmp(s, "x") == 0){
			multiply(stack);
			printf("Multiplying\n");
		}
        else if(strcmp(s,"^") == 0){
			power(stack);
			printf("Power\n");
        }
		else if(strcmp(s, "^2") == 0){
			squared(stack);
			printf("Squaring\n");
		}
		else if(strcmp(s, "^3") == 0){
			cubed(stack);
			printf("Cubing\n");
		}
		else if(strcmp(s, "abs") == 0){
			absoluteValue(stack);
			printf("Absolute value\n");
		}
		else if(strcmp(s, "sqrt") == 0){
			squareRoot(stack);
			printf("Square root\n");
		}
		else if(strcmp(s, "exp") == 0){
			exponential(stack);
			printf("Exponential\n");
		}
		else if(strcmp(s, "ln") == 0){
			naturalLog(stack);
			printf("Natural Log\n");
		}
		else if(strcmp(s, "log") == 0){
			logBase10(stack);
			printf("Log\n");
		}

        else{
    // FIXME: You need to develop the code here (when s is not an operator)
    // Remember to deal with special values ("pi" and "e")
    //check if not a number
            if (isNumber(s, &num) == 0){
                if (strcmp(s, "pi") == 0){
                    num = 3.14159265;
                }
                else if (strcmp(s, "e") == 0){
                    num = 2.7182818;
                }
                else{	//wrong
                    printf("%s is not valid (number or operator) \n", s);
                    break;
                }
            }
            pushDynArr(stack, num);
        }
    }	//end for
/* FIXME: You will write this part of the function (2 steps below)
* (1) Check if everything looks OK and produce an error if needed.
* (2) Store the final value in result and print it out.
*/
    if (sizeDynArr(stack) != 1) {
        printf("Incorrect count of numbers is detected! Calculations CANNOT be preformed. ");
        return 0;
    }
    else {
        result = topDynArr(stack);
    }
    return result;
}

int main(int argc , char** argv)
{
    double num;
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	num = calculate(argc,argv);
	printf("The answer = %f \n", num);
	return 0;
}
