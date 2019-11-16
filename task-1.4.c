#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0.00;
    upper = 300.00;
    step = 20.00;
    celsius = lower;

    printf("C\tF\n");

    //List celsius to fahrenheit conversions
    while(celsius <= upper)
    {
        fahr = celsius / (5.0/9.0) + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}