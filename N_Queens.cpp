#include <iostream>

class NQueens {
private:
    static const int N = 4;
    int board[N][N];

public:
    NQueens() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = 0;
            }
        }
    }

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << " " << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    bool isSafe(int row, int col) {
        for (int i = 0; i < col; i++) {
            if (board[row][i]) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]) {
                return false;
            }
        }

        for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
            if (board[i][j]) {
                return false;
            }
        }

        return true;
    }

    bool solveNQUtil(int col) {
        if (col >= N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (solveNQUtil(col + 1)) {
                    return true;
                }

                board[i][col] = 0; // Backtrack
            }
        }

        return false;
    }

    bool solveNQueens() {
        if (solveNQUtil(0) == false) {
            return false;
        }

        printSolution();
        return true;
    }
};

int main() {
    NQueens nQueens;

    if (nQueens.solveNQueens() == false) {
        std::cout << "Solution does not exist\n";
    }

    return 0;
}