#include<stdio.h>
#include<stdlib.h>
#include"gENFUNCTIONS.h"

/*
    Returns the content of specified file
*/
char *readFileFunction(const char *filename)
{
    char *data;
    long len;
    FILE *file = fopen(filename, "rb");
    if(file == NULL){return NULL;}

    fseek(file, 0, SEEK_END);

    len = ftell(file);
    rewind(file);

    data = malloc(len + 1);
    
    fread(data, 1, len, file);

    data[len] = '\0';

    fclose(file);
    return data;
}