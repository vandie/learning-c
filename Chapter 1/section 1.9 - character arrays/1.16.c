#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

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
        printf("%d - %s...", max, longest);
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
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}