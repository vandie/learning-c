#include <stdio.h>

/*
    Define lines allow you to define what amounts to symbolic constants without type
    This seems odd to have multiple ways to define a variable but I assume theres a reason
    Also, using define seems to ignore type. I wonder why

    Edit: turns out they arent variables at all they get replaced by the compiler as constants.
    All Caps is expected
*/
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    int fahr;

    for(fahr=LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}