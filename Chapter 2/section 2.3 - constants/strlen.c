#include <stdio.h>
#include <string.h> //strlen is in here

int main()
{
    char string[] = "This is a test string";
    int length = strlen(string);
    printf("The length of \"%s\" is %d\n", string, length);
}