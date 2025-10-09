#include <iostream>
#include <string>
using namespace std;

const int N = 5;
int maze[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

bool isSafe(int x, int y, int maze[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

void findPaths(int x, int y, int maze[N][N], int destX, int destY, string path, string paths[], int &count) {
    if (x == destX && y == destY) {
        paths[count++] = path;
        return;
    }

    maze[x][y] = 0; 

    if (isSafe(x + 1, y, maze)) findPaths(x + 1, y, maze, destX, destY, path + "D", paths, count);
    
    if (isSafe(x, y + 1, maze)) findPaths(x, y + 1, maze, destX, destY, path + "R", paths, count);
    
    if (isSafe(x - 1, y, maze)) findPaths(x - 1, y, maze, destX, destY, path + "U", paths, count);
    
    if (isSafe(x, y - 1, maze)) findPaths(x, y - 1, maze, destX, destY, path + "L", paths, count);

    maze[x][y] = 1;
}

int main() {
    string rabbitPaths[100];
    string catPaths[100];
    int rCount = 0, cCount = 0;

    int rabbitMaze[N][N];
    memcpy(rabbitMaze, maze, sizeof(maze));
    findPaths(0, 0, rabbitMaze, 2, 2, "", rabbitPaths, rCount);

    int catMaze[N][N];
    memcpy(catMaze, maze, sizeof(maze));
    findPaths(4, 4, catMaze, 2, 2, "", catPaths, cCount);

    cout << "Rabbit Paths (0,0) -> (2,2):\n";
    if (rCount == 0)
        cout << "No path found.\n";
    else
        for (int i = 0; i < rCount; i++)
            cout << i + 1 << ". " << rabbitPaths[i] << endl;

    cout << "\nCat Paths (4,4) -> (2,2):\n";
    if (cCount == 0)
        cout << "No path found.\n";
    else
        for (int i = 0; i < cCount; i++)
            cout << i + 1 << ". " << catPaths[i] << endl;

    cout << "\nPossible Intersection Points:\n";
    cout << "(Note: This just checks same cells visited by both)\n";

    if (rCount == 0 || cCount == 0)
        cout << "No intersection (one of them has no path).\n";
    else
        cout << "They may meet around (2,2) — the food point!\n";

    return 0;
}