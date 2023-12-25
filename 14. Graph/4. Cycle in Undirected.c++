#include<bits/stdc++.h>
using namespace std;

//Que.- Given a undirected disconnected graph with 'N' vertices and 'M' edges. Your task is to
//      return "Yes" if it cointains cycle else return "No"

// Time : O(N+M)
// Space : O(N+M)

bool isCyclicBFS(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int src){
    unordered_map<int, int> parent;

    parent[src] = -1;

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adjList[front]){
            if(visited[i] && parent[front] != i)
                return true;
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(unordered_map<int, list<int>> adjList, vector<bool> &visited, int node, int parent){
    visited[node] = true;

    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(adjList, visited, neighbour, node);
            if(cycleDetected)
                return true;
        }
        else if(neighbour != parent)
            return true;
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    // create adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(adjList, visited, i, -1);
            if(ans == true)
                return "Yes";
        }
    }

    return "No";
}