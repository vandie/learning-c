#include <stdio.h>

int main()
{
    //known bugs: lines will be offset is a char occurs more than 9 times
    int c, i, lastIndex, highest; //We need a few variables here
    int chars[100]; //for the example we're unlikely to need to track more than 100 characters
    int charCounts[100];// The numbers of occurences for each character

    highest = 0; //default the highest value to 0

    for(i = 0; i < 100; ++i) {//itterate through all positions
        chars[i] = -1; //set char value to -1 as -1 isn't a valid char
        charCounts[i] = 0; //set the the count to 0 as we don't want any bleed through in memory
    }

    while((c = getchar()) != EOF){ //Get inout
        if(c == '\n' || c == '\t') // if the character is a line break or tab
            c = ' '; // treat it as a space char
            
        for(i = 0; i < 100 && chars[i] != -1 && chars[i] != c; ++i)//set i to the current character or next empty space
            ; //null statment - see older examples
        
        if(chars[i] == -1) //if the char is -1 then it is the first blank space
            chars[i] = c; //set the blank space to the character
        
        ++charCounts[i]; //increase the count for this char
    }

    for(i = 0; i < 100 && chars[i] != -1; ++i){ //repeat until 100 or the last character that has been set
        lastIndex = i; //set the last index to this character index
        if(charCounts[i] > highest) //if this charater has been used more than the current highest
            highest = charCounts[i];//set as the new highest
    }

    printf("\n\n");//print a break
    while(highest > 0){//repeat until highest is 0
        printf("%d ", highest);//print the y label
        for(i = 0; i <= lastIndex; i++) {//repeat through all the characters until the last index
            if(charCounts[i] == highest) {//if the character usage matches the label
                printf("-|-");//output a line
                --charCounts[i];//decrease the count
            } else //otherwise
                printf("---"); //output a blank space
        }
        printf("\n"); //go to the next line
        highest--; //decrease the highest number by 1
    }
    printf("  ");//skip the y label column
    for(i = 0; i <= lastIndex; i++)//itterate through the valid characters
        printf(" %c ", chars[i]);//out put the characters as the x axis label
    printf("\n\n");//print a break
}