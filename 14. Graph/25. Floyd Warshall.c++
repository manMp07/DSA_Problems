#include<bits/stdc++.h>
using namespace std;

/*Que.**
The problem is to find the shortest distances between every pair of vertices in a given
edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n.
Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=1e9, it means there
is no edge from i to j.*/

void shortest_distance(vector<vector<int>>&matrix){
	int n = matrix.size();
	    
	for(int via = 0; via < n; via++){
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    // for negative cycle detection
    for(int i = 0; i < n; i++){
        if(matrix[i][i] < 0){
            cout << "Negative Cycle Present";
            return;
        }
    }
}