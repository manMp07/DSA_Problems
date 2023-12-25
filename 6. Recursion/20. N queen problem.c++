#include<bits/stdc++.h>
using namespace std;

//Que.- N Queen Problem

// Time : O(N!)
// Space : O(N*N)

void addAnswer(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> board, int n) {
    // checking row
    int x = row;
    int y = col;
    while(y >= 0){
        if(board[x][y] == 1)
            return false;
        y--;
    }

    // checking upper diagonal
    x = row;
    y = col;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // checking upper diagonal
    x = row;
    y = col;
    while(x < n && y >= 0){
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if(col == n){
        addAnswer(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            //backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n,0));
    solve(0, ans, board, n);

    return ans;
}

// Thoda sa optimized
// Time & Space are same

void addAnswer(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> board, int n,
    unordered_map<int, bool> &sameRow, unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal) {
    
    if(!sameRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[(n-1)+col-row])
        return true;
    else
        return false;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n,
    unordered_map<int, bool> &sameRow, unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal) {

    if(col == n){
        addAnswer(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n, sameRow, upperDiagonal, lowerDiagonal)) {
            sameRow[row] = true;
            upperDiagonal[row + col] = true;
            lowerDiagonal[(n-1) + col - row] = true;
            board[row][col] = 1;

            solve(col+1, ans, board, n, sameRow, upperDiagonal, lowerDiagonal);
            //backtrack
            sameRow[row] = false;
            upperDiagonal[row + col] = false;
            lowerDiagonal[(n-1) + col - row] = false;
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n,0));

    unordered_map<int, bool> sameRow; 
    unordered_map<int, bool> upperDiagonal; // row + col
    unordered_map<int, bool> lowerDiagonal; // (n-1) + col - row

    solve(0, ans, board, n, sameRow, upperDiagonal, lowerDiagonal);

    return ans;
}