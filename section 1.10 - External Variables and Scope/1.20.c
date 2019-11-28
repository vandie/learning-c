#include <stdio.h>

#define MAXTEXT 10000
#define SPACESINTAB 4

char text[MAXTEXT];

int getInput(void);
void sanitiseInput(void);

int main() {
    extern char text[];
    int textLength;

    textLength = getInput();
    if(textLength > 0){
        sanitiseInput();
        printf("\n%s", text);
    } else {
        printf("No Text Given");
    }

    return 0;
}

int getInput(void) {
    extern char text[];

    char c;
    int i, inputMax;

    inputMax = (MAXTEXT / 4) * 3; //Should auto round on account of being an int

    for (i = 0; i < inputMax && (c = getchar()) != EOF; i++)
        text[i] = c;

    text[i] = '\0';
    return i;
}

void sanitiseInput(void) {
    extern char text[];

    int i, oi, counter;
    char tempText[MAXTEXT];

    oi = 0;
    for (i = 0; i < MAXTEXT && text[i] != '\0'; i++)
    {
        if(text[i] == '\t') {
            for (counter = 0; counter < SPACESINTAB; counter++)
            {
                tempText[oi] = ' ';
                oi++;
            }
        } else {
            tempText[oi] = text[i];
            oi++;
        }
    }

    tempText[oi] = '\0';

    for (i = 0; i < MAXTEXT && (text[i] = tempText[i]) != '\0'; i++)
        ;

    text[i] = '\0';
}