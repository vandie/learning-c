#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 6 //anything more than this and you may overflow the int...

int hexValue(char x);

int main()
{
    char c;
    char string[MAX];
    unsigned int total = 0,
    length = 0,
    temp = 0,
    multiplier = 0,
    i = 0;
    printf("Please insert a HEX value: ");
    for(i = 0; i <= MAX && (c = getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;

    length = strlen(string);

    for(i = 0; i < length ; ++i) {
        c = string[i];
        if(isxdigit(c)) {
            multiplier = pow(16,length-(i+1));
            temp = hexValue(tolower(c));
            printf("Character %c equals %d * %d\n", c, temp, multiplier);
            total += temp * multiplier;
        } else {
            printf("\n\nError: %c is not a valid hexidecimal character\n", c);
            return 1;
        }
    }

    printf("Total Value: %d\n", total);
}

int hexValue(char x)
{
    switch(x){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            return 0;
    }
}