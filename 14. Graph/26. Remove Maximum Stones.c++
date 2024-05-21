#include<bits/stdc++.h>
using namespace std;

/*Que...

There are n stones at some integer coordinate points on a 2D plane. Each coordinate point
may have at most one stone.
You need to remove some stones. 
A stone can be removed if it shares either the same row or the same column as another stone
that has not been removed.
Given an array of stones of length n where stones[i] = [xi, yi] represents the location of
the ith stone, return the maximum possible number of stones that you can remove.
***/

/***Using Disjoint Set***/
//Time : O(N)
//Space : (2*(maxRox + maxCol))

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltiParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUltiParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int removeStones(vector<vector<int>> &stones){
	int n = stones.size();
	int maxRow = 0;
	int maxCol = 0;
	for(auto it : stones){
		maxRow = max(maxRow, it[0]);
		maxCol = max(maxCol, it[1]);
	}

	DisjointSet ds(maxRow + maxCol + 1);
	unordered_map<int, int> stoneNodes;

	for(auto it : stones){
		int nodeRow = it[0];
		int nodeCol = it[1] + maxRow + 1;

		ds.unionBySize(nodeRow, nodeCol);

		stoneNodes[nodeRow] = 1;
		stoneNodes[nodeCol] = 1;
	}

	int cnt = 0; //number of connected components
	for(auto it : stoneNodes){
		if(ds.findUltiParent(it.first) == it.first)
			cnt++;
	}

	return n - cnt; // total_stones - total_number_of_connected_components
}

/***This Can be done using BFS/DFS also***/