#include<bits/stdc++.h>
using namespace std;

/*Que.- You will be given an m x n grid, where each cell has the following values : 
    2  -  represents a rotten orange
    1  -  represents a Fresh orange
    0  -  represents an Empty Cell
    Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward,
    downwards, right, and left ) it becomes Rotten. 

    Return the minimum number of minutes required such that none of the cells has a Fresh
    Orange. If it's not possible, return -1.
*/

int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    int total = 0;
    queue<pair<int, int>> rotten;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 0)
                total++;
            if(grid[i][j] == 2)
                rotten.push( {i,j} );
        }
    }

    int time = 0, count = 0;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!rotten.empty()){
        int k = rotten.size();
        bool flag = false;
        while(k--){
            pair<int, int> front = rotten.front();
            rotten.pop(); count++;
            int x = front.first;
            int y = front.second;

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                    continue;

                grid[nx][ny] = 2;
                rotten.push( {nx, ny} );
                flag = true;
            }
        }

        if(flag)
            time++;
    }

    if(total == count)
        return time;
    else
        return -1;
}