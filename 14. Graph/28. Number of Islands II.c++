#include<bits/stdc++.h>
using namespace std;

/***Que.
You are given an n, m which means the row and column of the 2D matrix, and an array of size k
denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is
land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The
array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you
can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are
there in the matrix after each operation. You need to return an array of size k.

Note: An island means a group of 1s such that they share a common side.
*/

class DisjointSet {
    vector<int> parent;
    vector<int> size;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUltiParent(int node){
        if(parent[node] == node)
            return node;
        
        return parent[node] = findUltiParent(parent[node]); //Included Path Compression
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

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q){
    DisjointSet ds(n*m);
    vector<int> ans;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int islands = 0;

    for(int i = 0; i < q; i++){
        int row = queries[i][0];
        int col = queries[i][1];

        int node = row*m + col;
        // no need to do anything which is already an island
        if(visited[row][col]){
            ans.push_back(islands);
            continue;
        }

        visited[row][col] = true;
        islands++;

        for(int j = 0; j < 4; j++){
            int nx = row + dx[j];
            int ny = col + dy[j];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || !visited[nx][ny])
                continue;
            
            int adjNode = nx*m + ny;

            // connect them
            if(ds.findUltiParent(node) != ds.findUltiParent(adjNode)){
                islands--;
                ds.unionBySize(node, adjNode);
            }
        }

        ans.push_back(islands);
    }

    return ans;
}