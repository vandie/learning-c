#include <stdio.h>

#define ONWORD 1
#define OFFWORD 0


int main()
{
    //known bugs: lines will be offset is a word occurs more than 9 times
    int c, status, charCount, i, si, max;
    int wordLengths[10]; //anything bigger than 9 can be labled with 10+

    max = charCount = 0; //Start at 0
    status = OFFWORD; //start as off words
    for(i = 0; i <= 9; ++i)
        wordLengths[i] = 0; //default all the count values to 0

    while((c = getchar()) != EOF)
        if(status == ONWORD && (c == ' ' || c == '\n' || c == '\t')) {
            status = OFFWORD; //not on a word
            if(charCount > 9) // if the count is larger than 9. label as 10+
                ++wordLengths[9]; //arrays are zero indexed
            else
                ++wordLengths[charCount-1]; //1 less than char count
            charCount = 0; //reset the char count
        } else if(!(c == ' ' || c == '\n' || c == '\t')){ //if not on a break
            status = ONWORD; //now on a word
            ++charCount; //increase the current count
        }
    
    for(i = 0; i <= 9; ++i)//find the largest value and set max to that value
        if(wordLengths[i] > max)
            max = wordLengths[i];

    printf("\n\n"); //add a small break
    while(max != 0){ //while anything is left to output
        printf("%d ",max); //print out the y value on the graph
        for(i = 0; i <= 9; ++i) //itterate through the array
            if(wordLengths[i] == max){ //if the value is equal to the current y value
                --wordLengths[i]; //minus one from the value
                printf("-|-"); //add a bar to the chart
            } else
                printf("---"); //print a "blank space" to the value
        --max;//minus one from the max
        printf("\n");//go to the new line
    }
    printf("  "); //output a small space to allow the x axis labeling
    for(i = 0; i <= 9; ++i)// output the numbers 1-9 and then 10+
        if(i == 9)
            printf("10+\n\n");
        else
            printf(" %d ", i+1);
}