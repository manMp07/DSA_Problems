#include<bits/stdc++.h>
using namespace std;

// This can be used in both 0-based & 1-based indexing
class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltiParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findUltiParent(parent[node]); //Included Path Compression
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);

        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size is more intutive then Union by Rank.
    void unionBySize(int u, int v){
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7);

    // adding edges
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    //if 3 and 7 are in same component
    if(ds.findUltiParent(3) == ds.findUltiParent(7))
        cout << "Same\n";
    else cout << "Not Same\n";

    ds.unionBySize(3, 7);

    if(ds.findUltiParent(3) == ds.findUltiParent(7))
        cout << "Same\n";
    else cout << "Not Same\n";

    return 0;
}