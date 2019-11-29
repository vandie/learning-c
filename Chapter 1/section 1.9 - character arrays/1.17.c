#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main()
{
    int len; //we need to store the length for a little bit
    char line[MAXLINE]; /* current input line */

    while((len = getLine(line,MAXLINE)) > 0)//continue until an input of zero comes through
        if(len > 80) //check if the length is greater than 80
            printf("\nLength of %d is larger than 80:\n%s\n", len, line);//if so output it 
    return 0;
}

/* getLine: read a line into s, return value */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar()) != EOF && c != '\n'; ++i) {
        if(i<lim-1){ //by moving this bit here we allow the number to go past the array size limit
            s[i] = c;
        }
    }
    if(c =='\n') {
        s[i] = c;
        ++i;
    }
    
    return i;
}