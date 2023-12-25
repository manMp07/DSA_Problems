#include<bits/stdc++.h>
using namespace std;

//Que.-

// Time : O(N*logN)
// Space : O(1)

bool possibleCapacity(vector<int> arr, int totalDay, int capacity) {
    int day = 0;
    int load = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > capacity)
            return false;

        if(load + arr[i] <= capacity){
            load += arr[i];
        }
        else {
            day++;
            load = arr[i];
        }
    }day++;

    if(day <= totalDay)
        return true;

    return false;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < weights.size(); i++) {
        sum += weights[i];
        maxi = max(maxi, weights[i]);
    }

    int hi = sum;
    int lo = maxi;
    int mid;

    while(lo <= hi) {
        mid = (lo + hi)/2;
        if(possibleCapacity(weights, d, mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}