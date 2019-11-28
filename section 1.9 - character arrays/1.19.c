#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char to[], char from[], int size);


int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char reversed[MAXLINE]; /* current reversed line */

    while((len = getLine(line, MAXLINE)) > 0){
        reverse(reversed, line, len);
        printf("%s", reversed);
    }
}

/* getLine: read a line into s, return value */
int getLine(char s[], int lim)
{
    int c, i; // c is the  latest character, i is an index

    for (i=0; i<lim-1  && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c =='\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; in reverse order assume to is big enough */
void reverse(char to[], char from[], int size)
{
    int i, p, additional;
    additional = 0;
    while (from[size - additional] == '\n' || from[size - additional] == '\0')
        additional++;
    for (i = 0; (p = (size - i) - additional) >= 0 && (to[p] = from[i]) != '\0'; ++i)
        ;
    while(additional > 0) {
        to[size - additional] = from[size - additional];
        --additional;
    }
    return;
}