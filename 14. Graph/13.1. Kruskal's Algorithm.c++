#include<bits/stdc++.h>
#include<utility>
using namespace std;

//Que.- You are given a Undirected Graph of 'N' vertices(0 to N-1) and 'M' weighted 
//      edges.
//      You are supposed to return the minimum spanning tree where you need to
//      return Minimum weight of the MST using Kruskal's Algorithm.

// Time : O(M*logM)
// Space : O(N)

bool cmp(vector<int> &a, vector<int> &b){
    return (a[2] < b[2]);
}

// intializing parent & rank
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i; // self parent
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent) {
    if(parent[node] == node)
        return node;

    parent[node] = findParent(parent[node], parent); // path compression

    return parent[node];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v])
        parent[u] = v;

    else if(rank[u] > rank[v])
        parent[v] = u;

    else{ // same rank
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n){
    // sorted edges on basis of weights
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n); // intializing parent & rank

    int minCost = 0;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
  
        // Not in same component than make them union
        if(parent[u] != parent[v]){
            unionSet(u, v, parent, rank);
            minCost += w;
        }
    }

    return minCost;
}