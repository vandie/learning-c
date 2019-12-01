#include <stdio.h>
#include <ctype.h>

int any(char in[], char s[]);

int main()
{
    char in[] = "example";
    char s[] = "ma";
    printf("The first time a char from \"%s\" appears in \"%s\" is character %d\n",in,s,any(in,s));
}

int any(char in[], char s[])
{
    int i, j;
    for(i = 0; in[i] != '\0'; i++){
        j = -1;   
        while(in[i] != s[++j] && s[j] != '\0');
        if(s[j] != '\0')
            return i;
    }
}