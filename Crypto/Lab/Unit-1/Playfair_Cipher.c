#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 5

void searchCharacter(char key[ROWS][COLS],
                     char target,
                     int *row, int *col)
{

    // printf("TARGET to search : %c\n",target);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (key[i][j] == target)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
    // If the character is not found, set indices to -1
    *row = -1;
    *col = -1;
}

void removeSpaces(char text[])
{
    int length = strlen(text);
    int i, j = 0;

    // Remove spaces between characters
    for (i = 0; i < length; i++)
    {
        if (text[i] != ' ')
        {
            text[j++] = text[i];
        }
    }
    text[j] = '\0'; // Null-terminate the string after removing spaces
}

void addXBetweenPairs(char text[])
{
    int length = strlen(text);
    int i;

    // Insert 'X' between consecutive identical letters
    for (i = 0; i < length - 1; i++)
    {
        if (text[i] == text[i + 1])
        {
            // Shift elements to make space for 'X'
            for (int j = length; j > i + 1; j--)
            {
                text[j] = text[j - 1];
            }
            // Insert 'X' between identical letters
            text[i + 1] = 'X';
            length++;
            i++; // Skip the inserted 'X' in the next iteration
        }
    }
}

void addXAtEndIfNeeded(char text[])
{
    int length = strlen(text);

    // Check if the length is odd
    if (length % 2 != 0)
    {
        // Append 'X' at the end
        text[length] = 'X';
        text[length + 1] = '\0'; // Null-terminate the string after adding 'X'
    }
}

void convertToUpperCase(char *str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

void cleanText(char text[])
{
    // UPPER CASING
    convertToUpperCase(text);
    // Step 1: Remove spaces
    removeSpaces(text);
    // Step 2: Add 'X' between consecutive identical letters
    addXBetweenPairs(text);
    // Step 3: Add 'X' at the end if length is odd
    addXAtEndIfNeeded(text);
    //    printf("X ADDED REMOVED :%s\n", text);
    printf("Modified text: %s\n", text);
}

void encrypt()
{
    /// Variables Declaration
    char plaintext[128];
    char plaintext_upper[128];
    char encryptedtext[128];
    memset(plaintext_upper, '\0', sizeof(plaintext_upper));
    memset(plaintext, '\0', sizeof(plaintext));

    char keyword[16];
    /// KEY MAPPING MATRIX CREATION
    char key[5][5] = {
        {'M', 'O', 'N', 'A', 'R'},
        {'C', 'H', 'Y', 'B', 'D'},
        {'E', 'F', 'G', 'I', 'K'},
        {'L', 'P', 'Q', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Z'}};
    printf("\nEnter the plaintext (up to 128 characters): ");
    scanf(" %[^\n]", plaintext); // Read input with spaces
    // fgets(plaintext, sizeof(plaintext), stdin);
    int length = strlen(plaintext);
    if (plaintext[length - 1] == '\n')
        plaintext[--length] = '\0';
    /// STEP 1 : CLEANING THE TEXT BEFORE ENCRYPTION
    cleanText(plaintext);

    /// LOOPING OVER TO ENCRYPT THE MESSAGE 2 Words at a time
    for (int i = 0; i < strlen(plaintext); i += 2)
    {
        char char1 = plaintext[i];
        char char2 = plaintext[i + 1];
        /// Getting ROW and COLUMN for the text in the MATRIX
        int row1, col1;
        int row2, col2;
        searchCharacter(key, char1, &row1, &col1);
        searchCharacter(key, char2, &row2, &col2);
        /// SUBSTITUTION LOGIC IMPLEMENTATION
        if ((row1 != -1) && (row2 != -1))
        {
            if (row1 == row2)
            {
                /// If both have same row add 1 to column
                int col1_e = (col1 + 1) % 5;
                int col2_e = (col2 + 1) % 5;
                encryptedtext[i] = key[row1][col1_e];
                encryptedtext[i + 1] = key[row2][col2_e];
            }
            else if (col1 == col2)
            {
                /// If both have same row add 1 to column
                int row1_e = (row1 + 1) % 5;
                int row2_e = (row2 + 1) % 5;
                encryptedtext[i] = key[row1_e][col1];
                encryptedtext[i + 1] = key[row2_e][col2];
            }
            else if ((row1 != row2) && (col1 != col2))
            {
                /// IF BOTH AREN'T IN SAME ROW/COLUMN (RECALL THE RECTANGLE LOGIC)
                int col1_e = col2;
                int col2_e = col1;
                encryptedtext[i] = key[row1][col1_e];
                encryptedtext[i + 1] = key[row2][col2_e];
            }
            else
            {
                continue;
            }
        }
    }
    printf("ENCRYPTED TEXT IS: %s", encryptedtext);
}

void decrypt()
{

    /// IMPLEMENTATION IS SIMILAR TO ENCRYTION
    /// (BUT REVERSES THE SUBSTITUTION LOGIC row/col+1 to row/col - 1)
    /// NOTE : +5 is added as mod of -ve yields -ve number in C-Program
    char plaintext[128];
    char plaintext_upper[128];
    char encryptedtext[128];
    memset(plaintext_upper, '\0', sizeof(plaintext_upper));
    memset(plaintext, '\0', sizeof(plaintext));

    char keyword[16];

    char key[5][5] = {
        {'M', 'O', 'N', 'A', 'R'},
        {'C', 'H', 'Y', 'B', 'D'},
        {'E', 'F', 'G', 'I', 'K'},
        {'L', 'P', 'Q', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Z'}};
    printf("\nEnter the ENCRYPTED TEXT (up to 128 characters): ");
    scanf(" %[^\n]", plaintext); // Read input with spaces
    // fgets(plaintext, sizeof(plaintext), stdin);
    int length = strlen(plaintext);
    if (plaintext[length - 1] == '\n')
        plaintext[--length] = '\0';

    cleanText(plaintext);
    for (int i = 0; i < strlen(plaintext); i += 2)
    {
        // printf("%d", i);
        char char1 = plaintext[i];
        char char2 = plaintext[i + 1];
        // printf("char 1 %C", char1);
        int row1, col1;
        int row2, col2;
        searchCharacter(key, char1, &row1, &col1);
        searchCharacter(key, char2, &row2, &col2);
        // printf("ROW 1: %d \n ROW2: %d",row1, row2);
        if ((row1 != -1) && (row2 != -1))
        {
            if (row1 == row2)
            {
                /// If both have same row add 1 to column
                int col1_e = (col1 - 1 + 5) % 5;
                int col2_e = (col2 - 1 + 5) % 5;
                encryptedtext[i] = key[row1][col1_e];
                encryptedtext[i + 1] = key[row2][col2_e];
            }
            else if (col1 == col2)
            {
                /// If both have same row add 1 to column
                int row1_e = (row1 - 1 + 5) % 5;
                int row2_e = (row2 - 1 + 5) % 5;
                encryptedtext[i] = key[row1_e][col1];
                encryptedtext[i + 1] = key[row2_e][col2];
            }
            else if ((row1 != row2) && (col1 != col2))
            {
                int col1_e = col2;
                int col2_e = col1;
                encryptedtext[i] = key[row1][col1_e];
                encryptedtext[i + 1] = key[row2][col2_e];
            }
            else
            {
                continue;
            }
        }
    }
    printf("DECRYPTED TEXT IS: %s", encryptedtext);
}

int main()
{
    int option;

    while (1)
    {
        printf("\n1. Encrypt");
        printf("\n2. Decrypt");
        printf("\n3. Exit\n");
        printf("\nEnter your option: ");
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
            printf("\nInvalid selection! Try again.\n");
            break;
        }
    }
    return 0;
}
