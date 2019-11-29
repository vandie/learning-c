#include <stdio.h>

int main()
{
    int c, t, b, nl; //define c,t,b and nl
    
    nl = 0; //Set nl to 0
    while((c = getchar()) != EOF) //Random Thought. Is EOF defined using #define n studio.h?
    {
        if(c == '\t')
            ++t;
        
        if(c == ' ') //as c cannot have multiple values, we don't need to use else
            ++b;
            /*
                From reading a tab also counts as a blank character in C.
                As such, I'm taking the task to mean spaces
            */
        if(c == '\n')
            ++nl;
    }
    printf("%d tabs, %d blanks and %d new lines", t, b, nl);    
}