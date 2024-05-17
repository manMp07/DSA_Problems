#include<bits/stdc++.h>
using namespace std;

/*Que...
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size
rows x columns, where heights[row][col] represents the height of the cell (row, col). You
are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell,
(rows-1, columns-1) (i.e.,0-indexed). You can move up, down, left, or right, and you wish to
find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells
of the route.*/

/*Dijkstra's Algo*/
//Time : O(4*N*M*log(N*M))
//Space : O(N*M)

int minimumTimeTakingPath(vector<vector<int>> &heights){
    // {diff, {row, col}}
    priority_queue< pair<int,pair<int,int>>, 
    vector< pair<int,pair<int,int>> >,
    greater<pair<int, pair<int,int>> >> pq;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    
    dist[0][0] = 0;
    pq.push({0, {0,0}});

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if(row == n-1 && col == m-1)
            return diff;

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            int effort = max(abs(heights[row][col] - heights[nr][nc]), diff);
            if(effort < dist[nr][nc]){
                dist[nr][nc] = effort;
                pq.push({effort, {nr, nc}});
            }
        }
    }
}