#include <stdio.h>

int main()
{
    const int lim = 100; //not going to change. should be const
    int i = 0; //int i isn't constant as it is used in the loop
    char c, string[lim]; //create a char storage and string storage

    while(i < lim-1){
        if((c = getchar()) != '\n')
            if(c != EOF) {
                string[i] = c;
                ++i;
                continue;//ensure that the break isn't hit. Just a tad cleaner
            }
        break; //Escape the loop early
    }
}
