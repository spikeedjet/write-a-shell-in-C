#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This is an example.";
    char delimiters[] = " ,.!";  // Define delimiters (space, comma, period, exclamation mark)
    char *token;

    // Get the first token
    token = strtok(str, delimiters);

    // Walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
        // printf("2%s\n", token);

    }

    return 0;
}
