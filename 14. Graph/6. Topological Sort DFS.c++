#include <bits/stdc++.h>
using namespace std;

//Que.- Given a Directed Acyclic(Not Cyclic) Graph (DAG) with V vertices and E edges,
//      Find any Topological Sorting of that Graph using DFS.

// Time : O(V+E)
// Space : O(V+E)

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, stack<int> &s, int node) {
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]) {
            dfs(adjList, visited, s, neighbour);
        }
    }
    
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    stack<int> s;
    vector<bool> visited(v);

    for(int i = 0; i < v; i++){
        if(!visited[i])
            dfs(adjList, visited, s, i);
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}