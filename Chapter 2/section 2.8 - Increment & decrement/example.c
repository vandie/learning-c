#include <stdio.h>

void squeeze(char s[], int c);

int main()
{
    char input[] = "This is an example isn't it";
    printf("Removing the character 'i' from \"%s\" results in:\n", input );
    squeeze(input, 'i');
    printf("\"%s\"\n",input);
}

void squeeze(char s[], int c)
{
    int i, j;

    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}