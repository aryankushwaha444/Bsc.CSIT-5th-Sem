#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Encrypts the plantext using the caesar Cipher

void encrypt()
{
    char key[2];
    char plantext[127];

    printf("Enter Plaintext (upto 127 characters) : ");
    scanf("%s", plantext);

    printf("Enter Key ( A ,B, C .....) : ");
    scanf("%s", key);

    for (int i = 0; i < strlen(plantext); i++)
    {
        int shift = toupper(key[0]) - 'A';

        char encrytpText = toupper(((plantext[i])) - 'A' + shift) % 26 + 'A'; //
        printf("%c", encrytpText);
    }
}

void decrypt()
{
    char key[2];
    char plantext[127];

    printf("Enter Cipher Text (upto 127 charactera) : ");
    scanf("%s", plantext);

    printf("Enter Key ( A ,B, C .....) : ");
    scanf("%s", key);

    for (int i = 0; i < strlen(plantext); i++)
    {
        int shift = toupper(key[0]) - 'A';

        char decryptText = toupper(((plantext[i])) - 'A' - shift + 26) % 26 + 'A'; //
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
        printf("\n3).Exit \n");

        printf("\n1. Enter Your Option :");
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
            printf("\n Invalid Selection : Try Again .\n");
        }
    }


    return 0;
}