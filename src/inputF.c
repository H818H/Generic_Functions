#include"gENFUNCTIONS.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
#include<string.h>
#include<ctype.h>

/**
 * Handles user input with basic validation, depending on the expected type.
 * Supports int, float, double and string inputs.
 * Returns error codes on invalid input.
 */
int _inputFunction(const char *message, void *exit, TYPES type) 
{
    char buffer[STRING_SIZE];
    char *endp;
    int valid = 0;

    while(!valid) 
    {
        printf("%s", message);
        fgets(buffer, STRING_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        switch(type) 
        {
            case T_INT: 
            {
                long n_int = strtol(buffer, &endp, 10);
                if(*endp != '\0' || n_int < 0 || n_int > INT_MAX) 
                {
                    return ERROR_TOO_LONG_SHORT_NUMBER;
                } 
                else 
                {
                    *(int*)exit = (int)n_int;
                    valid = 1;
                }
                break;
            }
            case T_DOUBLE:
            {
                double n_double = strtod(buffer, &endp);
                if(*endp != '\0' || n_double < 0.0f || n_double > DBL_MAX)
                {
                    return ERROR_TOO_LONG_SHORT_NUMBER;
                }
                else
                {
                    *(double*)exit = n_double;
                    valid = 1;
                }
                break;
            }

            case T_FLOAT: 
            {  
                float n_float = strtof(buffer, &endp);
                if(*endp != '\0' || n_float < 0.0f || n_float > FLT_MAX) 
                {
                    return ERROR_TOO_LONG_SHORT_NUMBER;
                } 
                else
                {
                    *(float*)exit = n_float;
                    valid = 1;
                }
                break;
            }
            case T_STR:
                if(strlen(buffer) == 0) 
                {
                    return ERROR_VOID_INPUT;
                }
                else 
                {
                    strcpy((char*)exit, buffer);
                    valid = 1;
                }
                break;
            default:
                return ERROR_INVALID_INPUT;
        }
    }
    return 1;
}