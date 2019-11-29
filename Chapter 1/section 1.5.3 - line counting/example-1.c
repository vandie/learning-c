#include <stdio.h>

int main()
{
    int c, nl; //define c and nl as ints

    nl = 0; // nl needs to start at 0
    /*
        Personally I'd want more brackets here. I don't think it looks very clear.
        That being said, this is a pretty simple to understand line counting program.
    */
    while ((c = getchar()) != EOF) //itterate through characters
        if(c == '\n') //if character is a new line
            ++nl;// increase number of lines
    printf("%d\n", nl);
}