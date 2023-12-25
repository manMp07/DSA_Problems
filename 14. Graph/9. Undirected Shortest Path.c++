#include<bits/stdc++.h>
using namespace std;

//Que.- Given an Undirected Connected Graph having unit weight, find the shortest path from
//      the 'S' to 'T' in this graph. In this problem statement, we have assumed the
//      source vertex to be ‘1’.

// Time : O(N+E)
// Space : O(N+E)

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// create adjList
	unordered_map<int, list<int>> adjList;
	for(int i = 0; i < m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// Do BFS
	vector<bool> visited(n+1, false);
	vector<int> parent(n+1);
	queue<int> q;

	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()) {
		int front = q.front();
		q.pop();

		for(auto neighbour : adjList[front]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				parent[neighbour] = front;
				q.push(neighbour);
			}
		}
	}

	// prepare shortest path
	vector<int> ans;

	int curr = t;
	ans.push_back(curr);
	while(curr != s){
		curr = parent[curr];
		ans.push_back(curr);
	}

	reverse(ans.begin(), ans.end());

	return ans; 
}