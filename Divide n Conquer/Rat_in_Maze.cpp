#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int arr[][2], int row, int col, int x, int y, vector<vector<bool>>& visited){
  if(((x >=0 && x<row) && (y >= 0 && y < col)) && (arr[x][y] == 1) && (visited[x][y] == false)){
    return true;
  }
  else return false;
}

void solvemaze(int arr[][2], int row, int col, int i, int j, vector<vector<bool>>& visited, vector<string> &path, string output){
  //base case
  if(i == row-1 && j == col-1){
    path.push_back(output);

    return;
  }

  //down -> i+1,j
  if(isSafe(arr,row, col, i+1, j, visited)){
    visited[i+1][j] = true;
    //RE call
    solvemaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtracking
    visited[i+1][j] = false;
  }
  //Left -> i,j-1
  if(isSafe(arr,row, col, i, j-1, visited)){
    visited[i][j-1] = true;
    //RE call
    solvemaze(arr, row, col, i, j-1, visited, path, output + 'L');
    //backtracking
    visited[i][j-1] = false;
  }

  //right -> i,j+1
  if(isSafe(arr,row, col, i, j+1, visited)){
    visited[i][j+1] = true;
    //RE call
    solvemaze(arr, row, col, i, j+1, visited, path, output + 'R');
    //backtracking
    visited[i][j+1] = false;
  }

  //up -> i-1,j
  if(isSafe(arr,row, col, i-1, j, visited)){
    visited[i-1][j] = true;
    //RE call
    solvemaze(arr, row, col, i-1, j, visited, path, output + 'U');
    //backtracking
    visited[i-1][j] = false;
  }

}

int main() {
  int maze[2][2] = { {1,1},
                      {1,1}};

  int row = 2;
  int col = 2;

  if(maze[0][0] == 0){
      cout<<"No path exists"<<endl;
      return 0;
  }

  vector<vector<bool>> visited(row,vector<bool>(col,false));
  vector<string> path;
  string output = "";
 visited[0][0] = true;

  solvemaze(maze,row,col, 0 , 0, visited, path, output);
 
  for(auto it: path){
    cout<<it<<" ";
  } cout<<endl;

  if(path.size() == 0) 
  cout<<"No path exists"<<endl;

  return 0;
}