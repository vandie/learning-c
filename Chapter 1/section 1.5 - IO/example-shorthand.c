#include <stdio.h>

//Simple program to cpy input to output

int main()
{
    int c;

    /*
        The book suggests that a "better" C programmer would use this shorhand.
        While I agree that it is shorter,
        if this was JS I would call it bad and hacky.
        No doubt I've done this in the past though so not sure I can say anything
    */
    while ((c = getchar()) != EOF)
        putchar(c);
    
}