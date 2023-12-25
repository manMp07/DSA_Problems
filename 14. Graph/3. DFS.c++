#include<bits/stdc++.h>
using namespace std;

//Que.- Perform DFS traversal in disconnected graph

// Time : O(V+E)
// Sapce : O(V)

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, vector<int> &component, int node){

    component.push_back(node);
    visited[node] = true;

    for(auto i : adjList[node]){
        if(!visited[i])
            dfs(adjList, visited, component, i);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<vector<int>> ans;

    for(int i = 0; i < V; i++) {
        if(!visited[i]){
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}