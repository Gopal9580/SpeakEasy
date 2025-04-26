#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    char command[1200];

    printf("Enter the text you want to convert to speech:\n");
    fgets(text, sizeof(text), stdin);

    // Remove newline character if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    // Build the command for espeak
    snprintf(command, sizeof(command), "espeak \"%s\"", text);

    // Execute the command
    int result = system(command);

    if (result == -1) {
        printf("Failed to execute text-to-speech.\n");
    }

    return 0;
}
