#include <stdio.h>
#define MAXLINE 1000

int max; //some external variables, seems reasonable
char line[MAXLINE]; 
char longest[MAXLINE];

int getLine(void);
void copy(void);


int main()
{
    int len;
    extern int max; //this extern term is interesting. I wonder why they didn't use global?
    extern char longest[]; //apparantly extern is somtime optional based on context :shrug:

    while ((len = getLine()) > 0)
        if (len > max){
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);
    
    return 0;
}

int getLine(void)
{
    int c, i;
    extern char line[];

    for (i=0; i<MAXLINE-1  && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c =='\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;

    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}