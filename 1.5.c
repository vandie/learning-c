#include <stdio.h>

int main()
{
    int fahr;
    //repeat task 1.3a but use a C - for loop instead

    for(fahr=0; fahr <= 300; fahr = fahr + 20) //so far so normal
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
        /*
            The for loop doesn't seem to need {}.
            This is odd considering the strictness of C elsewhere
        */
}