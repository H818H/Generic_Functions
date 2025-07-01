#ifndef GENFUNCTIONS_H
#define GENFUNCTIONS_H

// Constants for string handling
#define STRING_SIZE 1024
#define INIT_SIZE 1
#define MAX_TOKENS_IN_ARRAY 200

/**
 * A dynamic array of strings (char*), managed manually.
 */
typedef struct
{
    char **array;   ///< Array of strings
    int index;      ///< Number of elements currently stored
    int capacity;   ///< Allocated size (number of strings)
}CHARARRAY;

/**
 * Frees all memory inside a CHARARRAY structure.
 * @param charArray Pointer to the CHARARRAY to be freed.
 */
void freeCharArray(CHARARRAY *charArray);

/**
 * Allocates initial memory for a CHARARRAY structure.
 * @param charArray Pointer to the CHARARRAY to initialize.
 * @return 1 on success, 0 on failure.
 */
int mallocCharArray(CHARARRAY *charArray);

/**
 * Doubles the capacity of the CHARARRAY.
 * @param charArray Pointer to the CHARARRAY to reallocate.
 * @return 1 on success, 0 on failure.
 */
int reallocCharArray(CHARARRAY *charArray);

/**
 * Adds a new string to the CHARARRAY.
 * @param charArray Pointer to the CHARARRAY.
 * @param str String to be copied and added.
 * @return 1 on success, 0 on failure.
 */
int appendToCharArray(CHARARRAY *charArray, const char *str);

/**
 * Frees a dynamically allocated array of strings.
 * @param array Pointer to the array of strings.
 * @param size Number of elements to free.
 */
void freeSplitArray(char **array, int size);

/**
 * Removes leading and trailing whitespace from a string.
 * @param str String to be trimmed (modified in place).
 * @return Pointer to the trimmed string.
 */
char *trimFunction(char *str);


/**
 * Splits a string by a delimiter and trims each token.
 * @param input Input string to split.
 * @param delimiter Delimiter used for splitting.
 * @param numTokens Output: number of tokens found.
 * @return Array of strings (must be freed with freeSplitArray).
 */
char **splitFunction(const char *input, const char *delimiter, int *numTokens);

// Error codes for _inputFunction
#define ERROR_TOO_LONG_SHORT_NUMBER 2
#define ERROR_VOID_INPUT 3
#define ERROR_INVALID_INPUT 4

/**
 * Supported input types for _inputFunction.
 */
typedef enum 
{
    T_INT,
    T_STR,
    T_FLOAT,
    T_DOUBLE
}TYPES;

/**
 * Handles typed user input from stdin with validation.
 * @param message Message to display.
 * @param exit Pointer to variable where input will be stored.
 * @param type Type of input expected (TYPES enum).
 * @return 1 on success, or an error code.
 */
int _inputFunction(const char *message, void *exit, TYPES type);

/**
 * Allocates suficient memory to store bytes of a file
 * Returns a pointer to this area. The buffer is terminated with '\0'  
 * @param filename file to read, must specifie directory if its out of current directory
 * @return a pointer containing all the data of specified file(must be freed with free())
 */
char *readFileFunction(const char *filename);

#endif
