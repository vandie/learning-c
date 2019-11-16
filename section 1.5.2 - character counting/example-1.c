#include <stdio.h>

//Output the length of a passed in string.

int main()
{
    /*
        So be defining a long so it can go up to at least 32 bits.
        The length of an int or a long can differ depending on the compiler and machine.
        The spec REQUIRES int to be at least 16 bits (often 32 however) and a long to be at least 32.
        Therefore, to avoid issues. It's wise to use a long for anything longer than 16 bits.
    */
    long nc;
    nc = 0;
    while(getchar() != EOF)
        ++nc;
    /*
        I asked before if C supports ++. it does. It also allows it before or after the variable name
        eg. nc++; or ++nc;
        I imagine most use nc++ as that is what went into other languages but I could be mistaken.
    */
    printf("%ld\n", nc); //Assuming %ld is to output a long
}