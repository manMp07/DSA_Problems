#include<bits/stdc++.h>
using namespace std;

//Que.- Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each
//      cell. The distance between two adjacent cells is 1.

//Time: O(N*M)
//Space: O(N*M)

vector<vector<int>> nearest(vector< vector<int>> & mat, int n, int m){
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1){
                ans[i][j] = 0;
                q.push({ {i, j}, 0 });
                vis[i][j] = true;
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();


        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == 1 || vis[nx][ny])
                continue;

            q.push({{nx, ny}, steps+1});
            ans[nx][ny] = steps+1;
            vis[nx][ny] = true;
        }
    }

    return ans;
}