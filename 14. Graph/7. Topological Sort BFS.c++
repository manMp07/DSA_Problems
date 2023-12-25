#include <bits/stdc++.h>
using namespace std;

//Que.- Given a Directed Acyclic(Not Cyclic) Graph (DAG) with V vertices and E edges,
//      Find any Topological Sorting of that Graph using BFS(Kahn's Algorithm).

/*** Kahn's Algorithm ***/
// Time : O(V+E)
// Space : O(V+E)

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // create adj list
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(v, 0);

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        
        indegree[v]++; // maintaining indegrees.
    }

    // 0 degree walo ko queue me push krdo
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbour : adjList[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}