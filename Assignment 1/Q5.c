/* CS261- Assignment 1 - Q.5*/
/* Name:tatyana vlaskin
 * Date:10.1.2014
 * Solution description:
 Write a function void sticky(char* word) where word is a single word such as “sticky” or “RANDOM”.
sticky() should modify the word to appear with “sticky caps” (http://en.wikipedia.org/wiki/StudlyCaps) , that
is, the letters must be in alternating cases(upper and lower), starting with upper case for the first letter. For
example, “sticky” becomes “StIcKy” and “RANDOM” becomes “RaNdOm”. Watch out for the end of the
string, which is denoted by ‘\0’. You can assume that legal strings are given to the sticky() function.
NOTE: You can use the toUpperCase(...) and toLowerCase(...) functions provided in the skeletal code to
change the case of a character. Notice that toUpperCase() assumes that the character is currently in lower
case. Therefore, you would have to check the case of a character before calling toUpperCase(). The same
applies for toLowerCase(). You may also use the 'C' library toupper or tolower.

SEE COMMENTS FOR SOLUTION DESCRIPTION
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){// used information on http://www.dotnetperls.com/uppercase-first-letter
     /*Convert to sticky caps*/
     int i;
     for(i=0; word[i] != '\0'; i++){ // Chart type is an array terminated by the null character, so we loop though the array
        if(word[i] >= 'a' && word[i] <= 'z'){//http://web.cs.mun.ca/~michael/c/ascii-table.html
            word[i] = toUpperCase(word[i]);// every single character in the word is converted to upper case
        }
     }

     for(i=1; word[i]!= '\0'; i = (i+2)){
        word[i] =toLowerCase(word[i]);// every letter at the odd index is converted to lower case
     }
}

int main(){
        /*Read word from the keyboard using scanf*/
    char entry[400];

    printf("Enter one word containing ONLY letter a through z: ");
    scanf("%s", entry);
    /*Call sticky*/
    sticky(entry);

    /*Print the new word*/
    printf("%s \n", entry);

    return 0;
}
