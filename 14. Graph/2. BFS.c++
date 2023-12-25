#include<bits/stdc++.h>
using namespace std;

//Que.- Given a adjacency list of a graph of N vertices starting from 0. Your task is
//      to return list consisting of BFS.
// Note : We can use 'set' instead of 'vector' for adjacency list if question asks
//        for a sorted neighbours.

// Time : O(N+M) ; N = Number of vertices
// Space : O(N) ; M = Number of edges

// For Connected Graph
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> visited(n,0);
    vector<int> ans;

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        
        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return ans;
}

// For Disconnected Graph
void bfsHelper(vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        
        for(auto i : adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> visited(n, 0);
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(!visited[i]){
            bfsHelper(adj, visited, ans, 0);
        }
    }

    return ans;
}