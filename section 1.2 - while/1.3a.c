#include <stdio.h>

int main()
{
    int fahr, celsius; //comma seperated definitions, similar to what JS allows
    int lower, upper, step; //Note: Definitions can include values but follow the book for now
    
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("F\tC\n"); //Headers for the task. F for fahrenheit and C for celsius
    
    //List fahrenheit to celsius conversions
    while(fahr <= upper) //Seems like a standard while loop. no issues here.
    {
        /*
            C isn't like JS, ints will do int math which is rounded.
            5/9 would become 0, which we obviously don't want
        */
        celsius = 5 * (fahr-32) / 9;
        /*
            As far as I can tell. %d is replaced by the next input value.
            %d appears to be instructing C to output this as a diget though. Think about RegEx
        */
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step; // Note: Check if C supports +=
    }
}