#include<bits/stdc++.h>
using namespace std;

//Que.- Given an undirected connected graph with V vertices and adjacency list adj.
//      You are required to find all the vertices removing which (and edges through
//      it) disconnect the graph into 2 or more components.

// Time : O(V+E)
// Space : O(V)

class Solution {
    int timer = 0;
    
    void dfs(vector<int>adj[], vector<int> &disc, vector<int> &low, vector<bool> &visited,
             vector<bool> &mark, int node, int parent){
                
        visited[node] = true;
        disc[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        for(auto nbr : adj[node]) {
            if(nbr == parent){
                continue;
            }
            if(!visited[nbr]){
                dfs(adj, disc, low, visited, mark, nbr, node);
                low[node] = min(low[node], low[nbr]);
                
                if(low[nbr] >= disc[node] && parent != -1){
                    mark[node] = true;
                }
                child++; // calculate non-visited childs onlys
            }
            else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if(parent == -1 && child > 1)
            mark[node] = true;
    }
    
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        vector<bool> visited(v, false);
        vector<bool> mark(v, false);
        
        vector<int> ap;
        
        dfs(adj, disc, low, visited, mark, 0, -1);
        
        for(int i = 0; i < v; i++) {
            if(mark[i])
                ap.push_back(i);
        }
        
        if(ap.empty())
            return {-1};
            
        return ap;
    }
};