#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **remove_duplicate(char **arguments) {
    int len = 0;
    int i = 0;
    int j = 0;
    char **result = NULL;
    char **hash_table = NULL;
    int hash_table_size = 0;

    // Determine the length of the arguments array
    while (arguments[len] != NULL) {
        len++;
    }

    // Allocate memory for the result array
    result = (char **) malloc((len + 1) * sizeof(char *));
    if (result == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the hash table
    hash_table_size = len * 2;
    hash_table = (char **) malloc(hash_table_size * sizeof(char *));
    if (hash_table == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the hash table to NULL
    for (i = 0; i < hash_table_size; i++) {
        hash_table[i] = NULL;
    }

    // Iterate through the arguments array and add unique values to the result array
    for (i = 0; i < len; i++) {
        // Calculate the hash value for the current argument
        int hash_value = 0;
        int name_len = strlen(arguments[i]);
        for (j = 0; j < name_len; j++) {
            hash_value = hash_value * 31 + arguments[i][j];
        }
        hash_value %= hash_table_size;

        // Check if the current argument is already in the hash table
        if (hash_table[hash_value] != NULL && strcmp(hash_table[hash_value], arguments[i]) == 0) {
            // Duplicate argument found, skip it
            continue;
        }

        // Add the current argument to the result array and hash table
        result[i] = arguments[i];
        hash_table[hash_value] = arguments[i];
    }
    result[i] = NULL;

    // Free the hash table memory
    free(hash_table);

    return result;
}

