#include <stdio.h>

#define MAXTEXT 100000
#define TRUE 1
#define FALSE 0

char code[MAXTEXT];

int inComment;
int inString;
int stringStarter;
int commentStarter;

int getInput(void);
void removeComments(void);

int main() {
    extern int inComment;
    extern int inString;
    extern char code[];

    int textLength;

    inComment = FALSE;
    inString = FALSE;

    textLength = getInput();
    if(textLength > 0){
        removeComments();
        printf("\n%s", code);
    }
    else
    {
        printf("No Input Given");
    }
}

int getInput() {
    extern char code[];
    int i;
    char c;

    for (i = 0; i < MAXTEXT && (c = getchar()) != EOF; ++i)
        code[i] = c;

    code[i] = '\0';
    return i;
}

void removeComments() {
    extern char code[];
    extern int inString;
    extern int inComment;
    extern int stringStarter;
    extern int commentStarter;

    int i, oi;
    char tempCode[MAXTEXT];

    inComment = FALSE;
    inString = FALSE;

    oi = 0;
    
    for (i = 1; code[i] != '\0' && i < MAXTEXT-1 && oi < MAXTEXT-1; i++) //start at one because we only care about double characters
    {
        if(inComment == FALSE) {
            if(inString == TRUE) {
                if(code[i] == stringStarter && code[i-1] != '/')
                    inString = FALSE;
            } else if(inString == FALSE && (code[i] == '"' || code[i] == '\'')) {
                inString = TRUE;
                stringStarter = code[i];
            } else if (inString == FALSE) {
                if(code[i] == '/' && code[i-1] == '/') {
                    commentStarter = '/';
                    inComment = TRUE;
                    --oi;
                } else if(code[i] == '*' && code[i-1] == '/') {
                    commentStarter = '*';
                    inComment = TRUE;
                    --oi;
                }
            }
        } else if(code[i] == '/' && code[i-1] == commentStarter) {
            inComment = FALSE;
        } else if(code[i] == '\n' && commentStarter == '/') {
            inComment = FALSE;
        }

        if(inComment == FALSE) {
            if (i == 1){
                tempCode[0] = code[0];
                ++oi;
            }
            tempCode[oi] = code[i];
            oi++;
        }
    }
    tempCode[oi] = '\0';
    for (i = 0; i < MAXTEXT && (code[i] = tempCode[i]) != '\0'; i++)
        ;
        
    code[oi] = '\0';
}