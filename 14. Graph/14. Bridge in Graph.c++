#include<bits/stdc++.h>
using namespace std;

//Que.- Given an undirected Graph, The task is to find the Bridges in this Graph.
//      Note : An edge in an undirected connected graph is a bridge if removing it
//      disconnects the graph. For a disconnected undirected graph, the definition
//      is similar, a bridge is an edge removal that increases the number of
//      disconnected components. 

/*** Using Tarjan's Algorithm ***/
// Time : O(N+E)
// Space : O(N)

int timer = 1;
void dfs(int node, unordered_map<int, vector<int>> &adjList, int parent, 
         vector<bool> &visited, vector<int> &low, vector<int> &tin,
         vector<vector<int>> &bridges){

    visited[node] = true;
    tin[node] = low[node] = timer;
    timer++;

    for(auto nbr : adjList[node]) {
        if(nbr == parent)
            continue;
        if(visited[nbr] == false) {
            dfs(nbr, adjList, node, visited, low, tin, bridges);
            low[node] = min(low[node], low[nbr]);

            if(low[nbr] > tin[node]) // it is a bridge
                bridges.push_back({node, nbr});
        }

        else {
            low[node] = min(low[node], tin[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, vector<int>> adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(v, false);
    vector<int> low(v, -1);
    vector<int> tin(v, -1); // time of insertion
    int parent = -1;

    vector<vector<int>> bridges;

    dfs(0, adjList, parent, visited, low, tin, bridges);

    return bridges;
}