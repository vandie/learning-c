#include <stdio.h>

int main()
{
    int c, lc; //no need for state here as we're simply doing a replace

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t'){
            if(c == lc) continue;//This second if does an early escape to avoid duplicate new lines
            putchar('\n');
        } else {
            putchar(c);
        }

        lc = c; //set last character to the current character
    }
}