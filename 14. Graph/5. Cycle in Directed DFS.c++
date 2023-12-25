#include<bits/stdc++.h>
using namespace std;

//Que.- Given a directed disconnected graph with 'N' vertices and 'M' edges. Your task is to
//      return 1 if it cointains cycle else return 0.

// Time : O(N+M)
// Space : O(N)

bool checkCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, 
                unordered_map<int, bool> &DFSvisited, int vertex) {
                
    visited[vertex] = true;
    DFSvisited[vertex] = true;
    
    for(auto neighbour : adj[vertex]){
        if(!visited[neighbour]){
            bool cycleFound = checkCycleDFS(adj, visited, DFSvisited, neighbour);
            if(cycleFound)
                return true;
        }
        else if(DFSvisited[neighbour])
            return true;
    }

    DFSvisited[vertex] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]){
            bool cycleFound = checkCycleDFS(adj, visited, DFSvisited, i);
            if(cycleFound)
                return true;
        }
    }
    return false;
}