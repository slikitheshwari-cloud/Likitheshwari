#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], int key) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base + key) % 26 + base;
        }
    }
}

void decrypt(char text[], int key) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base - key + 26) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (shift value): ");
    scanf("%d", &key);

    text[strcspn(text, "\n")] = '\0';

    encrypt(text, key);
    printf("\nEncrypted Message: %s\n", text);

    decrypt(text, key);
    printf("Decrypted Message: %s\n", text);

    return 0;
}
