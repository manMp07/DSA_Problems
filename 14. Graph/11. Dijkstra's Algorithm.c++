#include <bits/stdc++.h>
using namespace std;

//Que.- You are given a Undirected Graph of 'V' vertices(0 to N-1) and 'E' weighted
//      edges.
//      Return an array that stores the distance(sum of weights) of a shortest path
//      from vertex 'Source' to all vertices.

// Time : O((E+V)*logV) ~ O(E*logV) : By using set/minHeap
// Time : O(VlogV + E) : By Using Fibonacci Heap..
// Space : O(V+E)

/***Using Set***/

vector<int> dijkstra(vector<vector<int>> &edges, int v, int e, int source) {
    // create adjacency list
    unordered_map<int, list<pair<int, int>> > adjList;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // create distance array with infinite value initially
    vector<int> distance(v, INT_MAX);

    set<pair<int,int>> st; // pair<distance, node>

    // initialize distance and set with source node
    distance[source] = 0;
    st.insert({0, source});

    while(!st.empty()) {
        // fetch top record
        pair<int, int> top = *(st.begin());

        int nodeDistance = top.first;
        int node = top.second;
        st.erase(st.begin()); // remove top

        // traverse on neighbours
        for(auto neightbour : adjList[node]) {
            int adjNode = neightbour.first;
            int edgW = neightbour.second;

            if(nodeDistance + edgW < distance[adjNode]){

                auto record = st.find( {distance[adjNode], adjNode} );
                //if record found, then erase it
                if(record != st.end())
                    st.erase(record);

                /* /*Another way of erasing existing entry in set
                if(distance[adjNode] != INT_MAX)
                    st.erase({distance[adjNode], adjNode}); */
                    
                // distance update
                distance[adjNode] = nodeDistance + edgW;
                st.insert( {distance[adjNode], adjNode} );
            }
        }
    }

    return distance;
}