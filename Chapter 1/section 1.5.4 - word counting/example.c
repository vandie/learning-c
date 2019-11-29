#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* counts "words" */
int main()
{
    int c, nl, nw, nc, state;
    
    state = OUT; //Outside a word
    nl = nw = nc = 0; //Thats a chain. Set all 3 to 0. set by value ftw
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')// || and && are both in C. Woo!
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n",nl, nw, nc);
}