#include<bits/stdc++.h>
using namespace std;

//Que.- Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace
//      all 'O' with 'X' that is surrounded by 'X'. An 'O' (or a set of 'O') is considered
//      to be surrounded by 'X' if there are 'X' at locations just below, just above just
//      left, and just right of it.

//Time: O(N) + O(M) + O(N*M*4) ~ O(N*M)
//Space: O(N*M)

void dfs(vector<vector<char>> &board, int x, int y, vector<vector<bool>> &visited){
    int n = board.size();
    int m = board[0].size();

    visited[x][y] = true;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 'X')
            continue;

        dfs(board, nx, ny, visited);
    }
}

vector<vector<char>> captureRegion(vector<vector<char>> &board, int n, int m) {
    if(n < 3 || m < 3)
        return board;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int j = 0; j < m; j++){
        // first row
        if(!visited[0][j] && board[0][j] == 'O')
            dfs(board, 0, j, visited);

        // last row
        if(!visited[n-1][j] && board[n-1][j] == 'O')
            dfs(board, n-1, j, visited);
    }

    for(int i = 0; i < n; i++){
        //first column
        if(!visited[i][0] && board[i][0] == 'O')
            dfs(board, i, 0, visited);

        // last column
        if(!visited[i][m-1] && board[i][m-1] == 'O')
            dfs(board, i, m-1, visited);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
        }
    }

    return board;
}