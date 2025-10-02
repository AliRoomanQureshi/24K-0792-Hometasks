#include <iostream>
using namespace std;

#define MAX 20

int totalSolutions = 0;
char board[MAX][MAX];

void printBoard(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

bool solveNQueens(int row, int N, bool printOne) {
    if (row == N) {
        totalSolutions++;
        if (printOne) {
            cout<<"One valid solution:"<<endl;
            printBoard(N);
            return true;
        }
        return false;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, N)) {
            board[row][col] = 'Q';
            if (solveNQueens(row + 1, N, printOne)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    int N;
    cout<<"Enter value of N: ";
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';
    solveNQueens(0, N, true);
    totalSolutions = 0;
    solveNQueens(0, N, false);
    cout<<"Total distinct solutions: "<<totalSolutions<<endl;
    return 0;
}
