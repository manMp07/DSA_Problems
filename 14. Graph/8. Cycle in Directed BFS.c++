#include<bits/stdc++.h>
using namespace std;

//Que.- Given a undirected disconnected graph with 'N' vertices and 'M' edges. Your
//      task is to return 1 if it cointains cycle else return 0.

// Time : O(N+M)
// Space : O(N+M)

int topologicalSort(vector<pair<int, int>> &edges, int v, int e, unordered_map<int, list<int>> &adjList)  {
    // create adj list

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v+1);
    for(auto i : adjList){
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // 0 degree walo ko queue me push krdo
    queue<int> q;
    for(int i = 1; i <= v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbour : adjList[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return cnt;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> & edges) {
    unordered_map<int, list<int>> adjList;
    
    int count = topologicalSort(edges, n, edges.size(), adjList);

    if(count < n) // found invalid topological sort, means cycle present
        return true;
    else // found valid topological sort, means cycle not present
        return false;
}