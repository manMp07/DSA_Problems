#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a Directed Acycle Graph(DAG) of 'N' vertices(0 to N-1) and 'M'
//      weighted edges.
//      Return an array that stores the distance(sum of weights) of a shortest path
//      from vertex 0 to all vertices and if it is not impossible to reach any vertex,
//      then assign -1 as distance.

// Time : O(N+M)
// Space : O(N)

void dfs(unordered_map<int, list<pair<int, int>>> &adjList, vector<bool> &visited,
        stack<int> &s, int vertex) {

        visited[vertex] = true;

        for(auto i : adjList[vertex]){
            if(!visited[i.first]){
                dfs(adjList, visited, s, i.first);
            }
        }
        s.push(vertex);
    }

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    // create adjList with weight
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adjList[u].push_back({v, weight});
    }

    // Perform topological sort
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(adjList, visited, s, i);
    }

    vector<int> distance(n, INT_MAX);
    distance[0] = 0;

    while(!s.empty()) {
        int top =  s.top();
        s.pop();

        if(distance[top] != INT_MAX){
            for(auto i : adjList[top])
                if(distance[top] + i.second < distance[i.first])
                    distance[i.first] = distance[top] + i.second;
        }
    }

    for(int i = 0; i < distance.size(); i++){
        if(distance[i] == INT_MAX)
            distance[i] = -1;
    }

    return distance;
}