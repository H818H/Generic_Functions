#include"gENFUNCTIONS.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/**
 * Frees all strings and internal array in a CHARARRAY structure.
 */
void freeCharArray(CHARARRAY *charArray)
{
    for(int i = 0; i < charArray->capacity; i++)
    {
        if(charArray->array[i] != NULL)
        {
            free(charArray->array[i]);
        }
    }
    free(charArray->array);
    charArray->capacity = 0;
    charArray->index = 0;
}

/**
 * Allocates memory for the CHARARRAY structure and initializes its elements.
 */
int mallocCharArray(CHARARRAY *charArray)
{
    charArray->index = 0;
    charArray->capacity = INIT_SIZE;
    charArray->array = malloc(INIT_SIZE * sizeof(char*));
    if(charArray->array == NULL){return 0;}

    for(int i = 0; i < charArray->capacity; i++)
    {
        charArray->array[i] = malloc(STRING_SIZE * sizeof(char));
        if(charArray->array[i] == NULL){return 0;}
    }

    return 1;
}

/**
 * Reallocates the CHARARRAY structure, doubling its capacity.
 */
int reallocCharArray(CHARARRAY *charArray)
{
    int newCapacity = charArray->capacity * 2;
    char **temp = realloc(charArray->array, newCapacity * sizeof(char*));
    if(temp == NULL){return 0;}

    for(int i = charArray->capacity; i < newCapacity; i++)
    {
        temp[i] = malloc(STRING_SIZE * sizeof(char));
        if(temp[i] == NULL){return 0;}
    }

    charArray->array = temp;
    charArray->capacity = newCapacity;

    return 1;
}

/**
 * Appends a string to the CHARARRAY.
 */
int appendToCharArray(CHARARRAY *charArray, const char *str)
{
    if(charArray->index >= charArray->capacity)
    {
        if(!reallocCharArray(charArray)){return 0;}
    }
    strncpy(charArray->array[charArray->index], str, STRING_SIZE);
    charArray->index++;
    return 1;
}

/**
 * Trims whitespace from the beginning and end of a string.
 */
char* trimFunction(char *str)
{
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0){return str;}

    char *end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)){end--;}

    *(end + 1) = '\0';

    return str;
}

/**
 * Frees a dynamically allocated array of strings.
 */
void freeSplitArray(char **array, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        free(array[i]);
    }
    free(array);
}

/**
 * Splits a string by a delimiter and trims the resulting tokens.
 */
char **splitFunction(const char *input, const char *delimiter, int *numTokens)
{
    if(!input || !delimiter || !numTokens){return NULL;}

    char *inputCopy = malloc(strlen(input) + 1);
    if(inputCopy == NULL){return NULL;}
    strcpy(inputCopy, input);

    char **tokens = malloc(MAX_TOKENS_IN_ARRAY * sizeof(char*));
    if(tokens == NULL)
    {
        free(inputCopy);
        return NULL;
    }

    int count = 0;
    char *token = strtok(inputCopy, delimiter);
    while(token != NULL && count < MAX_TOKENS_IN_ARRAY)
    {
        token = trimFunction(token);

        tokens[count] = malloc(STRING_SIZE);
        if(!tokens[count])
        {
            for(int i = 0; i < count; i++){free(tokens[i]);}
            free(tokens);
            free(inputCopy);
            return NULL;
        }
        
        strncpy(tokens[count], token, STRING_SIZE - 1);
        tokens[count][STRING_SIZE - 1] = '\0';
        count++;
    
        token = strtok(NULL, delimiter);
    }

    *numTokens = count;
    free(inputCopy);
    return tokens;
}