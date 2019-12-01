#include <stdio.h>
#include <limits.h> //Has a few useful values in

int main()
{
    printf("A signed char must be between %d and %d\n",SCHAR_MIN, SCHAR_MAX);
    printf("An unsigned char must be between 0 and %d\n", UCHAR_MAX);

    printf("A signed int must be between %d and %d\n",INT_MIN, INT_MAX);
    printf("An unsigned int must be between 0 and %u\n", UINT_MAX);

    printf("A signed long must be between %ld and %ld\n",LONG_MIN, LONG_MAX);
    printf("An unsigned long must be between 0 and %lu\n", ULONG_MAX);

    printf("A signed short must be between %d and %d\n", SHRT_MIN, SHRT_MAX);
    printf("An unsigned short must be between 0 and %d\n", USHRT_MAX);
}