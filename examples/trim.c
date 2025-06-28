#include "gENFUNCTIONS.h"
#include <stdio.h>
#include <string.h>

int main() {
    char myString[STRING_SIZE];

    // Example string with spaces
    strcpy(myString, "    Hello, World!   ");

    printf("Original string: \"%s\"\n", myString);

    // Trim spaces
    char* trimmed = trimFunction(myString);

    printf("Trimmed string: \"%s\"\n", trimmed);

    return 0;
}