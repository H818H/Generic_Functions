#include"gENFUNCTIONS.h"
#include<stdio.h>

int main()
{
    char input[] = "apple, banana, cherry, pineapple";
    
    // numTokens will store how many strings were extracted
    // It is needed to correctly free memory later
    int numTokens = 0;

    // Call splitFunction() to split the input string using ',' as delimiter
    char **tokens = splitFunction(input, ",", &numTokens);
    if(tokens == NULL) // Always check in case memory allocation fails
    {
        printf("ERROR: tokens is null\n");
        return 1;
    }

    // Display the tokens
    printf("Number of tokens found: %d\n", numTokens);
    for(int i = 0; i < numTokens; i++)
    {
        printf("[%d]: %s\n", i, tokens[i]);
    }

    // Free memory used by the tokens
    freeSplitArray(tokens, numTokens); 
    
    return 0;
}