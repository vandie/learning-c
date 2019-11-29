#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline); // The book wanted this to be called getline but that conflicts now?
void copy(char to[], char from[]);

/* print the longest line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line is saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max){
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    
    return 0;
}

/* getLine: read a line into s, return value */
int getLine(char s[], int lim)
{
    int c, i; // c is the  latest character, i is an index

    /* 
        while i is less than the limit - 1 and we haven't hit the end of a line
    */
    for (i=0; i<lim-1  && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c; // set the current index of the array to the inputted char
    if(c =='\n') { //if the next char is a new line
        s[i] = c; //add the new line to the array
        ++i; //increase the index
    }
    s[i] = '\0'; // add an escape char
    return i; // return the current index as it is equal to the length of the line
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}