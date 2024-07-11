#include <stdio.h>
#include <stdint.h>
#include <string.h>

// PC-1 table: Permuted Choice 1 (drops parity bits)
int PC1[] = {
    //First Batch (C)
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    // Second Batch (D)
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

// PC-2 table: Permuted Choice 2
int PC2[] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

// Number of left shifts per round
int left_shifts[] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
};

// Function prototypes
void permuted_choice_1(uint8_t* key, uint8_t* pc1_result);
void permuted_choice_2(uint8_t* key, uint8_t* pc2_result);
void left_shift(uint8_t* key_half, int num_shifts);
void generate_subkeys(uint8_t* key, uint8_t subkeys[16][48]);

/*
 * @brief Apply PC-1 permutation to drop parity bits and get 56-bit key.
 *
 * @param key 64-bit input key
 * @param pc1_result 56-bit output after applying PC-1
 */
void permuted_choice_1(uint8_t* key, uint8_t* pc1_result) {
    for (int i = 0; i < 56; i++) {
        int byte_index = (PC1[i] - 1) / 8;
        int bit_index = (PC1[i] - 1) % 8;
        pc1_result[i] = (key[byte_index] >> (7 - bit_index)) & 0x01;
    }
}

/*
 * @brief Apply PC-2 permutation to get 48-bit subkey.
 *
 * @param key 56-bit input key
 * @param pc2_result 48-bit output subkey after applying PC-2
 */
void permuted_choice_2(uint8_t* key, uint8_t* pc2_result) {
    for (int i = 0; i < 48; i++) {
        pc2_result[i] = key[PC2[i] - 1];
    }
}

/*
 * @brief Perform left circular shift on a 28-bit key half.
 *
 * @param key_half 28-bit key half
 * @param num_shifts Number of positions to shift
 */
void left_shift(uint8_t* key_half, int num_shifts) {
    uint8_t temp[28];
    memcpy(temp, key_half, 28);

    for (int i = 0; i < 28; i++) {
        key_half[i] = temp[(i + num_shifts) % 28];
    }
}

/*
 * @brief Generate 16 subkeys for DES encryption.
 *
 * @param key 64-bit input key
 * @param subkeys 2D array to store 16 subkeys (each 48 bits)
 */
void generate_subkeys(uint8_t* key, uint8_t subkeys[16][48]) {
    uint8_t pc1_result[56];
    uint8_t C[28], D[28], combined[56];

    // Apply PC-1 to the original key
    permuted_choice_1(key, pc1_result);

    // Split into C and D halves
    memcpy(C, pc1_result, 28);
    memcpy(D, pc1_result + 28, 28);

    // Generate 16 subkeys
    for (int round = 0; round < 16; round++) {
        // Left shift C and D
        left_shift(C, left_shifts[round]);
        left_shift(D, left_shifts[round]);

        // Combine C and D
        memcpy(combined, C, 28);
        memcpy(combined + 28, D, 28);

        // Apply PC-2 to get the subkey
        permuted_choice_2(combined, subkeys[round]);
    }
}

// Function to print subkeys for demonstration purposes
void print_subkeys(uint8_t subkeys[16][48]) {
    for (int i = 0; i < 16; i++) {
        printf("Subkey %2d: ", i + 1);
        for (int j = 0; j < 48; j++) {
            printf("%d", subkeys[i][j]);
        }
        printf("\n");
    }

}

int main() {
    uint8_t key[8] = {0xA1, 0xB1, 0xC1, 0xD1, 0xE1, 0xF1, 0x11, 0xFF}; // Example key
    uint8_t subkeys[16][48];

    generate_subkeys(key, subkeys);
    print_subkeys(subkeys);


    return 0;
}