#include <stdio.h>
#include <string.h>

int main() {
    char text[101];
    int i;
    int shift = 3;   // shift key for Caesar Cipher

    printf("Enter text (5 - 100 characters): ");
    getchar();                 // clear buffer
    fgets(text, 101, stdin);

    // remove newline from fgets
    text[strcspn(text, "\n")] = '\0';

    // check length
    if(strlen(text) < 5 || strlen(text) > 100) {
        printf("Text length must be between 5 and 100 characters.\n");
        return 0;
    }

    // encryption process
    for(i = 0; text[i] != '\0'; i++) {

        // lowercase letters
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] + shift;
            if(text[i] > 'z')
                text[i] = text[i] - 26;
        }
        // uppercase letters
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + shift;
            if(text[i] > 'Z')
                text[i] = text[i] - 26;
        }
        // other characters remain unchanged
    }

    printf("Encrypted text: %s\n", text);

    return 0;
}
