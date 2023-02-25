

int main() {
    char* input;
    while ((input = readline("> ")) != NULL) {
        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(0);
        } else if (strncmp(input, "exit ", 5) == 0) {
            char* endptr;
            long status = strtol(input + 5, &endptr, 10);
            if (errno != ERANGE && endptr != input + 5 && *endptr == '\0') {
                free(input);
                exit((int)status);
            }
        }
        printf("You entered: %s\n", input);
        add_history(input);
        free(input);
    }
    return 0;
}
