#include <stdio.h>

//Simple program to cpy input to output

int main()
{
    int c; //Use an int to ensure there is enough space to store any character that can be typed

    c = getchar(); //Get next character of input
    while (c != EOF) //Book says to use != while every programmer instinct is telling me to use !==
    {
        putchar(c); //Output character
        c = getchar();   
    }
    
}