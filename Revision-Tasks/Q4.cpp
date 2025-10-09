
// If no safe route exists, the algorithm will try all possible moves recursively and eventually backtrack all the way to the start (0,0) — finding no complete path to the destination.
#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int maze[N][N], int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && !visited[x][y]);
}

void printPath(bool visited[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (visited[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << endl;
}

void findPath(int maze[N][N], int x, int y, bool visited[N][N]) {
    if (x == N - 1 && y == N - 1) {
        visited[x][y] = true;
        printPath(visited);
        visited[x][y] = false;
        return;
    }

    visited[x][y] = true;

    // Move Down
    if (isSafe(maze, x + 1, y, visited))
        findPath(maze, x + 1, y, visited);

    // Move Right
    if (isSafe(maze, x, y + 1, visited))
        findPath(maze, x, y + 1, visited);

    // Move Up
    if (isSafe(maze, x - 1, y, visited))
        findPath(maze, x - 1, y, visited);

    // Move Left
    if (isSafe(maze, x, y - 1, visited))
        findPath(maze, x, y - 1, visited);

    visited[x][y] = false; // Backtrack
}

int main() {
    int maze[N][N] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    bool visited[N][N] = {false};
    cout << "Path from start to destination:\n";
    findPath(maze, 0, 0, visited);
    return 0;
}
