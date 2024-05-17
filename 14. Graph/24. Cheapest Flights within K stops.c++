#include<bits/stdc++.h>
using namespace std;

/*Que...
There are n cities and m edges connected by some number of flights. You are given an array
of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from
city fromi to city toi with cost price. You have also given three integers src, dst, and k,
and return the cheapest price from src to dst with at most k stops. If there is no such
route, return -1.*/

/***Modification of Dijkstra's algo*/
//Time : O(N); used simple queue
//Space : O(N+M)

int cheapestFlights(int n, int source, int destination, int K, vector<vector<int>> &flights){
    vector<pair<int,int>> adjList[n];
    for(int i = 0; i < flights.size(); i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int price = flights[i][2];

        adjList[u].push_back({v, price});
    }

    queue<pair<int, pair<int, int>>> q; //{stops, {node, dist}}
    vector<int> dist(n, 1e9);
    dist[source] = 0;
    q.push({0, {source, 0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int currDist = it.second.second;

        if(stops == K+1)
            break;

        for(auto neighbour : adjList[node]){
            int next = neighbour.first;
            int wt = neighbour.second;

            if(currDist + wt < dist[next] && stops <= K){
                dist[next] = currDist + wt;
                q.push({stops+1, {next, dist[next]}});
            }
        }
    }

    if(dist[destination] == 1e9)
        return -1;

    return dist[destination];
}