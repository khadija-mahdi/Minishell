#include <stdio.h>
#include <string.h>

void sort_strings(char **strings, int num_strings) {
    int i, j, min_index;
    char *temp;

    for (i = 0; i < num_strings - 1; i++) {
        min_index = i;
        for (j = i + 1; j < num_strings; j++) {
            if (strcmp(strings[j], strings[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = strings[i];
            strings[i] = strings[min_index];
            strings[min_index] = temp;
        }
    }
}

int main() {
    char *strings[] = {"banana", "apple", "pear", "orange", "grape"};
    int num_strings = sizeof(strings) / sizeof(strings[0]);

    sort_strings(strings, num_strings);

    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
