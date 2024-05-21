#include<bits/stdc++.h>
using namespace std;

//Que.- Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
//      Find the number of strongly connected components in the graph.
// Note : If we can reach every vertex of a component from every other vertex in
//        that component then it is called a Strongly Connected Component (SCC).
//        Single node is always a SCC.

// Time : O(V+E)
// Space : O(V+E)

#include<bits/stdc++.h>

void dfs(unordered_map<int, list<int>> &adjList, vector<bool> &visited, int node) {
	visited[node] =  true;
	for(auto i : adjList[node]){
		if(!visited[i])
			dfs(adjList, visited, i);
	}
}

void topoSort(unordered_map<int, list<int>> &adjList, stack<int> &st,
			  vector<bool> &visited, int node) {
	visited[node] = true;

	for(auto i : adjList[node]){
		if(!visited[i])
			topoSort(adjList, st, visited, i);
	}
	st.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
	unordered_map<int, list<int>> adjList;
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}

	// Do Topological sort
	stack<int> st;
	vector<bool> visited(v, false);
	for(int i = 0; i < v; i++) {
		if(!visited[i])
			topoSort(adjList, st, visited, i);
	}

	// reverse entire graph's edges
	unordered_map<int, list<int>> reverseAdjList;
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		reverseAdjList[v].push_back(u);
	}

	// mark entire visited to false again
	for(int i = 0; i < v; i++)
		visited[i] = false;

	// do dfs using topoSort & reverseAdjList
	int sccCount = 0;
	while(!st.empty()) {
		int top = st.top();
		st.pop();

		if(!visited[top]){
			sccCount++;
			dfs(reverseAdjList, visited, top);
		}
	}

	return sccCount;
}