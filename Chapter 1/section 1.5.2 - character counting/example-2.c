#include <stdio.h>

//Output the length of a passed in string.

int main()
{
    /*
        A double is a double precision float. It is longer than a long so can be used if
        we expect super long text. used for the example by book
    */
    double nc;
    
    for(nc = 0; getchar() != EOF; ++nc) //Using a for loop. Seems reasonable
        ;
    /*
        This shorthand is gross imho. At very least I'd want this on the previous line.
        It works because nc is defined in the scope of main() so the for loop just increments it
        This in theory could work in JS too but I can't imagine it passing code review

        EDIT: Acording to the book. This syntax is called a null statment and is used frequently.
    */
    printf("%.0f\n", nc); //Acording to the book, %f supports both floats and doubles
}