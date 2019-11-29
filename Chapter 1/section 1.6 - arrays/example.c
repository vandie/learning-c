#include <stdio.h>

/* count digets, white space, others */
int main()
{
    int c, i, nwhite, nother;
    int ndiget[10]; //Not sure I like that the array is set on the variable name

    nwhite = nother = 0; //Set chains seem really useful
    for(i = 0; i< 10; ++i) //Lovely zero indexed arrays :)
        ndiget[i] = 0;
    
    while((c = getchar()) != EOF)
        if(c >= '0' && c <= '9')
            ++ndiget[c-'0'];
        else if(c == ' ' || c == '\n' || c == '\t') 
            ++nwhite; //I love that the book just explained that else if is a common thing
        else
            ++nother;
    
    printf("digets =");
    for(i = 0; i < 10; ++i)
        printf(" %d", ndiget[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

//seems like the program examples are starting to get a little bit longer