#include"gENFUNCTIONS.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // First, allocate memory for the CHARARRAY structure
    // NOTE: you don't need to manually create a "char **array" — the function does that for you
    CHARARRAY *ca = malloc(sizeof(CHARARRAY));
    if(ca == NULL)
    {
        printf("ERROR: memory allocation failed\n");
        return 1;
    }

    // This variable holds the response from mallocCharArray()
    // It returns 1 on success; 0 indicates failure
    int response = mallocCharArray(ca);    
    if(response == 0)
    {
        printf("ERROR: mallocCharArray() failed!\n");
        free(ca);
        return 1;
    }


    // NOTE: This function initially allocates memory for just two elements.
    // To add more elements, you need to call reallocCharArray()

    // Use appendToCharArray() to add strings to the array
    // Strings are stored in order of insertion: index 0, 1, 2, ...
    appendToCharArray(ca, "Hello, World"); // index: 0
    appendToCharArray(ca, "from function!"); // index: 1 
    
    for(int i = 0; i < ca->index; i++)
    {
        printf("index:%d\t element:%s\n", i, ca->array[i]);
    }

    // reallocCharArray() doubles the capacity each time it's called.
    // Example: starts with 2 → becomes 4 → 8 → 16 ...
    reallocCharArray(ca);

    // To free the internal array
    freeCharArray(ca);
    // Then free the structure itself
    free(ca);

    return 0;
}