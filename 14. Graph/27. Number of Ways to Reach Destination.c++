#include<bits/stdc++.h>
using namespace std;

/***Que.
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional
roads between some intersections. The inputs are generated such that you can reach any
intersection from any other intersection and that there is at most one road between any two
intersections.

You are given an integer n and a 2D integer array ‘roads’ where roads[i] = [ui, vi, timei]
means that there is a road between intersections ui and vi that takes timei minutes to travel.
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in
the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time.
Since the answer may be large, return it modulo 109 + 7.
***/

/***Modification of Dijkstra's Algorithm***/
//Time : O(ElogV)
//Space : O(V+E)

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adjList[n];
    for (auto it : roads){
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, 1e9);
    vector<int> ways(n, 0);

    ways[0] = 1;
    dist[0] = 0;
    pq.push({0, 0});

    int mod = 1000000007;
    while (!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto it : adjList[node]){
            int v = it.first;
            int wt = it.second;

            if(distance + wt < dist[v]){
                dist[v] = distance + wt;
                ways[v] = ways[node];
                pq.push({distance + wt, v});
            }
            else if(distance + wt == dist[v]){
                ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
    }

    return (ways[n-1] % mod);
}