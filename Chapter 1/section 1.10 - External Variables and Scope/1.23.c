#include <stdio.h>

#define MAXTEXT 100000
#define TRUE 1
#define FALSE 0

#define COMMENT 0
#define STRING 1
#define BRACKET 2
#define BRACE 3
#define SQUAREBRACE 4


char code[MAXTEXT];
int in[12];

int getInput(void);
void syntaxCheck(void);

int main() {
    extern char code[];

    int textLength;

    textLength = getInput();
    if(textLength > 0){
        syntaxCheck();
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

void syntaxCheck() {
    extern char code[];
    extern int in[];

    int i;

    for (i = 0; i < 12; ++i)
        in[i] = FALSE;

    for (i = 0; code[i] != '\0' && i < MAXTEXT - 1; i++)
    {
        if(in[COMMENT] == FALSE) {
            if(code[i] == in[STRING] && code[i-1] != '/') {
                in[STRING] = FALSE;
            } else if(in[STRING] == FALSE && (code[i] == '"' || code[i] == '\'')) {
                in[STRING] = code[i];
            } else if (in[STRING] == FALSE) {
                if(code[i] == '/' && code[i-1] == '/') {
                    in[COMMENT] = '/';
                } else if(code[i] == '*' && code[i-1] == '/') {
                    in[COMMENT] = '*';
                } else if(code[i] == '(') {
                    in[BRACKET]++;
                } else if(code[i] == '}') {
                    in[BRACKET]--;
                } else if(code[i] == '{') {
                    in[BRACE]++;
                } else if(code[i] == '}') {
                    in[BRACE]--;
                } else if(code[i] == '[') {
                    in[SQUAREBRACE]++;
                } else if(code[i] == ']') {
                    in[SQUAREBRACE]--;
                }
                //This method does have a flaw. This code will not pick up an error in which you have ) before ( as the number of brackets, braces or square braces will be balenced
            }
        } else if(code[i] == '/' && code[i-1] == in[COMMENT]) {
            in[COMMENT] = FALSE;
        } else if(code[i] == '\n' && in[COMMENT] == '/') {
            in[COMMENT] = FALSE;
        }
    }

    for (i = 0; i < 12; ++i){
        if(in[i] != FALSE){
            switch (i)
            {
            case COMMENT:
                printf("Syntax Error: Unended comment\n");
                break;
            case STRING:
                printf("Syntax Error: Unended quote\n");
                break;
            case BRACKET:
                printf("Syntax Error: Unended bracket\n");
                break;
            case BRACE:
                printf("Syntax Error: Unended brace\n");
                break;
            case SQUAREBRACE:
                printf("Syntax Error: Unended square brace\n");
                break;
            default:
                break;
            }
        }
    }
}