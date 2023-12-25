#include<bits/stdc++.h>
using namespace std;

//Que.- Given a weighted directed graph with negative edge weights with N nodes and
//      M edges. Nodes are labeled from 1 to N, the task is to find the shortest
//      distance from the source node to all other nodes.

// Time : O(N*M)
// Space : O(N)

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    return dist;

    // check for negative cycle
    /*
    bool flag = false;
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] + wt < dist[v])
            flag = true;
    }*/

    //if(flag) //Graph contains negative weight cycle
}