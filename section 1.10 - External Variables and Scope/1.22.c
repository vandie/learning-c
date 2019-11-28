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
        getInput();
        removeComments();
        printf("\n\n%s", code);
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

    for (i = 0; i < MAXTEXT && (c = getchar()) != EOF; i++)
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

    oi = 0;
    
    for (i = 0; code[i] != '\0'; i++)
    {
        if(inComment == FALSE)
            if(inString == TRUE)
                if(code[i] == stringStarter && code[i-1] != '/')
                    inString = FALSE;
            else if(inString == FALSE && (code[i] == '"' || code[i] == '\'')) {
                inString = TRUE;
                stringStarter = code[i];
            } else if (inString == FALSE)
                if(code[i] == '/' && code[i-1] == '/') {
                    commentStarter = '/';
                    inComment = TRUE;
                } else if(code[i] == '*' && code[i-1] == '/') {
                    commentStarter = '*';
                    inComment = TRUE;
                }
        else if(code[i] == '/' && code[i-1] == commentStarter)
            inComment = FALSE;
        
        if(inComment == FALSE) {
            tempCode[oi] = code[i];
            oi++;
        }
    }

    for (i = 0; tempCode[i] != '\0'; i++)
        code[i] = tempCode[i];
}