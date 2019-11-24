#include <stdio.h>

int fahrToCelsius(int fahr); //Define the template for the function

int main()
{
    int fahr;

    for(fahr=0; fahr <= 300; fahr = fahr + 20)
        printf("%d %d\n", fahr, fahrToCelsius(fahr));
}

int fahrToCelsius(int fahr)
{
    /* 
        Had to remember this is an int type not a float type.
        Got tripped because of JS' none typed functions :D
    */
    return 5 * (fahr-32) / 9;
}