#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 30;
const int COLS = 30;

void displayGrid(char grid[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int countNeighbors(char grid[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int r = row + i;
            int c = col + j;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && grid[r][c] == '*')
            {
                count++;
            }
        }
    }
    return count;
}

void updateGrid(char grid[ROWS][COLS])
{
    char newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == '*')
            {
                if (neighbors == 2 || neighbors == 3)
                {
                    newGrid[i][j] = '*';
                }
                else
                {
                    newGrid[i][j] = ' ';
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    newGrid[i][j] = '*';
                }
                else
                {
                    newGrid[i][j] = ' ';
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main()
{
    char grid[ROWS][COLS];
    srand(time(0));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2 == 0 ? '*' : ' ';
        }
    }

    while (true)
    {
        displayGrid(grid);
        updateGrid(grid);
        cin.get();
    }

    return 0;
}
