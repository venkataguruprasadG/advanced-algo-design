#include <iostream>
using namespace std;

const int N = 2;

bool solveMaze(int maze[N][N], int row, int col, int solution[N][N])
{
    // Outside the maze or blocked
    if (row < 0 || row >= N ||
        col < 0 || col >= N ||
        maze[row][col] == 0)
    {
        return false;
    }

    // Reached destination
    if (row == N - 1 && col == N - 1)
    {
        solution[row][col] = 1;
        return true;
    }

    // Choose this cell
    solution[row][col] = 1;

    // Try Down
    if (solveMaze(maze, row + 1, col, solution))
        return true;

    // Try Right
    if (solveMaze(maze, row, col + 1, solution))
        return true;

    // Try Up
    if (solveMaze(maze, row - 1, col, solution))
        return true;

    // Try Left
    if (solveMaze(maze, row, col - 1, solution))
        return true;

    // No direction worked → backtrack
    solution[row][col] = 0;

    return false;
}

int main()
{
    int maze[N][N] =
        {
            {1, 1},
            {0, 1}};

    int solution[N][N] = {0};

    if (solveMaze(maze, 0, 0, solution))
    {
        cout << "Path found:" << endl;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << solution[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}