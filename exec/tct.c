
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_string(char ***ptr, char *str, int len) {
    char **new_ptr = malloc((len + 1) * sizeof(char*));  // Allocate space for new pointer
    for (int i = 0; i < len; i++) {
        new_ptr[i] = (*ptr)[i];  // Copy old strings
    }
    new_ptr[len] = malloc(strlen(str) + 1);  // Allocate space for new string
    strcpy(new_ptr[len], str);  // Copy new string
    free(*ptr);  // Free old pointer
    *ptr = new_ptr;  // Set new pointer
}

int main() {
    char **ptr = malloc(2 * sizeof(char*));  // Allocate space for two strings
    ptr[0] = "Hello";
    ptr[1] = "world";
    int len = 2;
    add_string(&ptr, "!", len);  // Add new string
    len++;
    for (int i = 0; i < len; i++) {
        printf("%s ", ptr[i]);
    }
    free(ptr[2]);  // Free memory for new string
    free(ptr);  // Free memory for double pointer
    return 0;
}



































1. Allocate memory for the new string using malloc() function.
2. Copy the contents of the new string into the allocated memory using the strcpy() function.
3. Add the new string to the double pointer by assigning the address of the allocated memory to the next available element in the double pointer.
