#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("F\tC\n");

    //List fahrenheit to celsius conversions without being rounded to whole numbers
    while(fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        /*
            As expected %d is just for ints %f gives floats.
            Interestingly, the number of places can be changed using the following table
            
            %d Decimal int
            %6d print a Decimal Int at least 6 characters wide (000006)
            %f print as floating point
            %6f print as floating point at least 6 characters wide (0000006.0)
            %.2 print as floating point with 2 chatacters after decimal point (6.00)
            %6.2 print as floating point at least 6 characters wide with 2 chatacters after decimal point (0000006.00)

            These types are very strict. You cannot pass an int to a %f and you cannot pass a float to a %d etc.
        */
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}