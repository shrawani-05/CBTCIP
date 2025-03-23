#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int words = 0, lines = 0, characters = 0;
    int inWord = 0;

    // Get the file name from user
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            if (inWord) {
                words++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    // Count the last word if file doesn't end with space or newline
    if (inWord) {
        words++;
    }

    // Close the file
    fclose(file);

    // Display results
    printf("\nFile Analysis:\n");
    printf("Total Characters: %d\n", characters);
    printf("Total Words: %d\n", words);
    printf("Total Lines: %d\n", lines);

    return 0;
}
