#include <stdio.h>

void squeeze(char s[], char r[]);

int main()
{
    char input[] = "this is an example isn't it";
    char vowels[] ="aeiou";
    printf("Removing vowels from \"%s\" results in:\n", input );
    squeeze(input, vowels);
    printf("\"%s\"\n",input);
}

void squeeze(char s[], char r[])
{
    int i, j, k, l;

    for(i = j = 0; s[i] != '\0'; i++){
        for(l = k = 0; r[k] != '\0'; k++)
            if(s[i] == r[k])
                l = 1;
        if(!l)
            s[j++] = s[i];
    }
    s[j] = '\0';
}