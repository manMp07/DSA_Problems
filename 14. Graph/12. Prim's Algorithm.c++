#include <bits/stdc++.h>
using namespace std;

//Que.- You are given a Undirected Graph of 'N' vertices(1 to N-1) and 'M' weighted 
//      edges.
//      You are supposed to return the minimum spanning tree where you need to
//      return weight of each edge in MST.

// Time : O(N*N)
// Space : O(N)

int findMinimum(vector<int> &weight, vector<bool> &mst) {
    int mini = INT_MAX;
    int u = -1;
    for(int v = 1; v < weight.size(); v++){
        if(!mst[v] && weight[v] < mini){
            mini = weight[v];
            u = v;
        }
    }
    return u;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    // create adjList
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);
    vector<int> weight(n+1, INT_MAX);

    // let's start the algo
    weight[1] = 0;
    parent[1] = -1;

    while(true) {
        // find min wali node
        int u = findMinimum(weight, mst);
        
        // all nodes are included in MST
        if(u == -1)
            break;

        // mark min node as true
        mst[u] = true;

        // check for adjacency nodes
        for(auto neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(mst[v] == false && w < weight[v]){
                weight[v] = w; // update the weight
                parent[v] = u; // update the parent
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int v = 2; v <= n; v++) {
        ans.push_back({{parent[v], v}, weight[v]});
    }

    return ans;
}