#include<bits/stdc++.h>
using namespace std;

//Que.- Given weights and values of N items, we need to put these items in a knapsack
//      of capacity W to get the maximum total value in the knapsack.
//      Note: Unlike 0/1 knapsack, you are allowed to break the item.

//Time : O(N*LogN)
//Space : O(N)

bool cmp(vector<double>&a, vector<double>&b){
    return a[0] > b[0];
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    //items[i].first = weight
    //items[i].second = value

    vector<vector<double>> perUnitWeight(n, vector<double>(3));
    for(int i = 0; i < n; i++){
        perUnitWeight[i][0] = (1.0*items[i].second) / items[i].first; //unit weight
        perUnitWeight[i][1] = items[i].second; // value
        perUnitWeight[i][2] = items[i].first; // weight
    }

    sort(perUnitWeight.begin(), perUnitWeight.end(), cmp);

    double totalValue = 0;
    for(int i = 0; i < n; i++){
        if(perUnitWeight[i][2] <= w){
            w = w - perUnitWeight[i][2];
            totalValue += perUnitWeight[i][1];
        }
        else{
            totalValue += perUnitWeight[i][0]*w;
            w = 0;
        }
    }

    return totalValue;
}