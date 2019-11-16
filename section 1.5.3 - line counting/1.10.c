#include <stdio.h>

int main()
{
    int c;
    while((c = getchar()) != EOF) {
        if(c == '\b'){
            putchar('\\');
            putchar('b');
            continue; //Figured this was in C from JS. Seems like a C sorta thing
        }

        if(c == '\t'){
            putchar('\\'); //Ther must be a way to put multiple chars in at the same time
            putchar('t');
            continue;
        }

        if(c == '\\'){
            putchar('\\');
            putchar('\\');
            continue;
        }

        putchar(c); // if it isn't one of the special cases, just output it
    }
}