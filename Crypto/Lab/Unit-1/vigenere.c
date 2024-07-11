/// Vigenere Cipher

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Encrypt the ciphertext using the Vigenère Cipher

void encrypt()
{
    char key[20];
    char plaintext[127];

    printf("Enter plaintext (upto 127 charactera) : ");
    scanf("%s", plaintext);

    printf("Enter Key ( A ,B, C .....) : ");
    scanf("%s", key);

    for (int i = 0, j = 0; i < strlen(plaintext); i++, j++)
    {
        int shift = toupper(key[j % strlen(key)]) - 'A';

        char encrytpText = toupper(((plaintext[i])) - 'A' + shift) % 26 + 'A';
        printf("%c", encrytpText);
    }
}

// Decrypts the ciphertext using the Vigenère Cipher
void decrypt()
{
    char key[20];
    char ciphertext[127];

    printf("Enter Cipher Text (upto 127 characters): ");
    scanf("%s", ciphertext);

    printf("Enter Key (A, B, C, ...): ");
    scanf("%s", key);

    int keyLength = strlen(key);
    int textLength = strlen(ciphertext);

    for (int i = 0; i < textLength; i++)
    {
        int shift = toupper(key[i % keyLength]) - 'A'; // Adjusted to use key characters in a loop

        char decryptText = (((toupper(ciphertext[i])) - 'A' - shift) + 26) % 26 + 'A'; // Adjusted decryption formula
        printf("%c", decryptText);
    }
}

int main()
{
    int option;
    while (1)
    {
        printf("\n1). Encrypt");
        printf("\n2). Decrypt");
        printf("\n3). Exit \n");

        printf("\nEnter Your Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            encrypt();
            break;

        case 2:
            decrypt();
            break;

        case 3:
            printf("\n\tName :- Aaryan Kushawaha\n");
            printf("\tT.U Roll No. :- 28900/78");
            exit(0);

        default:
            printf("\nInvalid Selection: Try Again.\n");
        }
    }

    return 0;
}
