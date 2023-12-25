#include<bits/stdc++.h>
using namespace std;

//Que.- Undirected Graph

// Time : O(N+M)
// Space : O(N+M)

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> & edges) {
    vector<int> ans[n]; // 2D array
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adjList(n);

    for(int i = 0; i < n; i++) {
        adjList[i].push_back(i);

        for(int j = 0; j < ans[i].size(); j++){
            adjList[i].push_back(ans[i][j]);
        }
    }

    return adjList;
}