#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int newx, int newy, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
    {
        return true;
    }
    return false;
}

void printAllways(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << endl;
        return;
    }

    // UP (i-1, j)
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // jate huye visited ko true krdo
        visited[newx][newy] = true;
        output.push_back('U');
        printAllways(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        // backtracling
        visited[newx][newy] = false;
    }

    // DOWN (i+1, j)
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // jate huye visited make true
        visited[newx][newy] = true;
        output.push_back('D');
        printAllways(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        // backtrack
        visited[newx][newy] = false;
    }

    // left (i, j-1)
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('L');
        printAllways(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }

    // right (i, j+1)
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        visited[newx][newy] = true;
        output.push_back('R');
        printAllways(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{
    // int maze[4][4] = {
    //     {1, 0, 0, 0},
    //     {1, 1, 0, 1},
    //     {1, 1, 1, 0},
    //     {1, 1, 1, 1}};

    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 1}};
    int row = 4;
    int col = 4;
    string output;
    int srcx = 0;
    int srcy = 0;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    printAllways(maze, row, col, srcx, srcy, output, visited);
}