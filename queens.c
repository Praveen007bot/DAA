#include <stdio.h>

#define N 8  // number of queens

void printSolution(int board[N][N]) {
    // print the solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col) {
    // check if a queen can be placed at board[row][col]
    int i, j;

    // check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }

    // check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

int solveNQUtil(int board[N][N], int col) {
    // solve the n Queens problem recursively
    if (col == N) {
        printSolution(board);
        return 1;
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0; // backtrack
        }
    }

    return res;
}

int solveNQ() {
    // create a 2D array to represent the chessboard
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist");
        return 0;
    }

    return 1;
}

int main() {
    solveNQ();
    return 0;
}
