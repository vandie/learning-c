#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main()
{
    int line[MAXLINE];

    while( getLine(line, MAXLINE) > 0 ) {//get lines as written
        printf("%s", line);//output the modified line
    }
}

int getLine(char s[], int lim)
{
    int c, i;//define c and i

    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)// get the line to the array
        s[i] = c;
    
    while(s[i-1] == ' ' || s[i-1] == '\t') {//while the last char is a tab or space
        s[i-1] == '\0';//replace it with empty
        i--;//go back one more space
    }
        
    if(c == "\n")//if c is a new line
        s[i] = c;//set c to a new line
        i++;//increase i again

    s[i] = '\0';

    return i;
}

