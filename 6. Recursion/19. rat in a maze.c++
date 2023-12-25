#include<bits/stdc++.h>
using namespace std;

//Que.- Rat in a Maze problem

// Time : O(4^(N^2))
// Space : O(N*N)

bool isSafe(int x, int y, vector<vector<int>> arr, int n, vector<vector<bool>> &visited){
    if((0 <= x && x < n) && (0 <= y && y < n) && (arr[x][y] == 1) && (visited[x][y] == 0))
        return true;
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> arr, int n, vector<vector<bool>> &visited,
    vector<string> &ans, string path){
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if(isSafe(x+1, y, arr, n, visited))
            solve(x+1, y, arr, n, visited, ans, path + 'D');
        
        // Left
        if(isSafe(x, y-1, arr, n, visited))
            solve(x, y-1, arr, n, visited, ans, path + 'L');
        
        // Right
        if(isSafe(x, y+1, arr, n, visited))
            solve(x, y+1, arr, n, visited, ans, path + 'R');

        // Up
        if(isSafe(x-1, y, arr, n, visited))
            solve(x-1, y, arr, n, visited, ans, path + 'U');

        visited[x][y] = 0;
    }

vector<string> searchMaze(vector<vector<int>> & arr, int n) {
    vector<string> ans;
    
    if(arr[0][0] == 0)
        return ans;

    //DLRU
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    
    string path = "";
    
    solve(0, 0, arr, n, visited, ans, path);
    
    return ans;
}