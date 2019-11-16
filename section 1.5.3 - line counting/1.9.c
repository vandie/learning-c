#include <stdio.h>

int main()
{
    int c, lc;

    while((c = getchar()) != EOF) {
        /*
            if a char is not a space, output it.
            If it is, ensure it's the first before outputting it
        */
        if(c != lc || c != ' ')
            putchar(c);
        lc = c;
    }
}