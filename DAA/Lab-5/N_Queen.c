#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool solveNQUtil(int** board, int N, int* ld, int* rd, int* cl, int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            if (solveNQUtil(board, N, ld, rd, cl, col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }
    return false;
}

bool solveNQ(int N) {
    int** board = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        board[i] = (int*)malloc(N * sizeof(int));

    int* ld = (int*)malloc((2 * N - 1) * sizeof(int));
    int* rd = (int*)malloc((2 * N - 1) * sizeof(int));
    int* cl = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    for (int i = 0; i < 2 * N - 1; i++) {
        ld[i] = 0;
        rd[i] = 0;
    }

    for (int i = 0; i < N; i++)
        cl[i] = 0;

    if (solveNQUtil(board, N, ld, rd, cl, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board, N);

    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
    free(ld);
    free(rd);
    free(cl);

    return true;
}

int main() {
    int N;
    printf("Enter the size of the board (N): ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}
