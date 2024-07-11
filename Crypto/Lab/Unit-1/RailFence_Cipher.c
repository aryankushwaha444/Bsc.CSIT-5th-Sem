#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove spaces from the plaintext
void remove_spaces(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
}

// Function to encrypt using the Rail Fence Cipher
void encrypt(char *plaintext, int depth) {
    int len = strlen(plaintext);
    char rail[depth][len];
    memset(rail, '\n', sizeof(rail));  // Initialize the array with newline characters

    int row = 0, col = 0;
    int direction = 1; // 1 for down, -1 for up

    // Fill the rail matrix with characters in zigzag pattern
    for (int i = 0; i < len; i++) {
        rail[row][col++] = plaintext[i];
        if (row == 0) {
            direction = 1; // Start moving down
        } else if (row == depth - 1) {
            direction = -1; // Start moving up
        }
        row += direction;
    }

    // Read the matrix row-wise to get the ciphertext
    printf("Encrypted Text: ");
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] != '\n') {
                printf("%c", rail[i][j]);
            }
        }
    }
    printf("\n");
}

// Function to decrypt using the Rail Fence Cipher
void decrypt(char *ciphertext, int depth) {
    int len = strlen(ciphertext);
    char rail[depth][len];
    memset(rail, '\n', sizeof(rail));  // Initialize the array with newline characters

    int row = 0, col = 0;
    int direction = 1; // 1 for down, -1 for up

    // Mark the positions in the rail matrix to place characters
    for (int i = 0; i < len; i++) {
        rail[row][col++] = '*';
        if (row == 0) {
            direction = 1; // Start moving down
        } else if (row == depth - 1) {
            direction = -1; // Start moving up
        }
        row += direction;
    }

    // Fill the rail matrix with ciphertext characters
    int index = 0;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len) {
                if (ciphertext[index] != ' ') {
                    rail[i][j] = ciphertext[index++];
                } else {
                    index++; // Skip space in ciphertext
                }
            }
        }
    }

    // Read the matrix in zig-zag manner to get the plaintext
    printf("Decrypted Text: ");
    row = 0, col = 0;
    direction = 1;

    for (int i = 0; i < len; i++) {
        if (rail[row][col] != '\n') {
            printf("%c", rail[row][col++]);
        }
        if (row == 0) {
            direction = 1;
        } else if (row == depth - 1) {
            direction = -1;
        }
        row += direction;
    }
    printf("\n");
}


int main() {
    int option;
    char text[128];
    int depth;

    while (1) {
        printf("\n1). Encrypt");
        printf("\n2). Decrypt");
        printf("\n3). Exit \n");

        printf("\nEnter Your Option: ");
        scanf("%d", &option);

        getchar(); // Consume the newline character left by previous input

        switch (option) {
            case 1:
                printf("Enter Plaintext (up to 127 characters): ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';  // Remove the newline character

                printf("Enter depth (number of rails): ");
                scanf("%d", &depth);

                remove_spaces(text);
                encrypt(text, depth);
                break;

            case 2:
                printf("Enter Ciphertext (up to 127 characters): ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';  // Remove the newline character

                printf("Enter depth (number of rails): ");
                scanf("%d", &depth);

                decrypt(text, depth);
                break;

            case 3:
                printf("\n\tName :- Aaryan Kushawaha\n");
                printf("\tT.U Roll No. :- 28900/78\n");
                exit(0);

            default:
                printf("\nInvalid Selection: Try Again.\n");
        }
    }

    return 0;
}
