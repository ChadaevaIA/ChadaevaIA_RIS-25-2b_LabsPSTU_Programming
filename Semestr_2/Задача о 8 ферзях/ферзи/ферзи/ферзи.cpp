#include <iostream>
#include <cmath>
using namespace std;

const int N = 8;
int board[N]; 
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col) 
        {
            return false;         
        }
        if (abs(board[i] - col) == abs(i - row)) 
        {
            return false;
        }
    }
    return true;
}

void printBoard() {
    cout << "\nРешение #" << ++solutionCount << "\n\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
            {
                cout << " Q ";
            }
            else
            {
                cout << " . ";
            }
        }
        cout << "\n";
    }

    cout << "\n----------------------------------------\n";
}

void game(int row) {
    if (row == N) {
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            
            board[row] = col;
            game(row + 1);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    game(0);
    return 0;
}