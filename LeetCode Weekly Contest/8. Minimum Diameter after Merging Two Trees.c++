#include<bits/stdc++.h>
using namespace std;

// Weekly Contest 404 (Que.4)
// DATE : 30 July 2024

//Que.- Given edges of Two Tree with N & M nodes. You must connect one node from the
//      first tree with another node from the second tree with an edge.
//      Return the minimum possible diameter of the resulting tree.
//      The diameter of a tree is the length of the longest path between any two
//      nodes in the tree.

// 1 <= n, m <= 1e5

/*Hint : Find Diameter of both tree and process further*/

void dfs(vector<int> adjList[], int node, int parent, int dist[]){
    for(int v : adjList[node]){
        if(v == parent) continue;

        dist[v] = dist[node] + 1;
        dfs(adjList, v, node, dist);
    }
}

int getDiameter(vector<vector<int>>& edges, int n){
    vector<int> adjList[n];
    for(int i = 0; i < n-1; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int dist[n];
    dist[0] = 0;
    dfs(adjList, 0, -1, dist);

    int maxDist = 0;
    int maxDistNode = 0;
    for(int v = 1; v < n; v++){
        if(dist[v] > maxDist){
            maxDist = dist[v];
            maxDistNode = v;
        }
        dist[v] = 0;
    }

    dfs(adjList, maxDistNode, -1, dist);

    int diameter = 0;
    for(int it : dist)
        diameter = max(diameter, it);

    return diameter;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int d1 = getDiameter(edges1, edges1.size()+1);
    int d2 = getDiameter(edges2, edges2.size()+1);

    return max({d1, d2, 1 + (d1+1)/2 + (d2+1)/2});
}