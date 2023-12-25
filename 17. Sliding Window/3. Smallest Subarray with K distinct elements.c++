#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array 'A' consisting of N integers, find the smallest subarray
//      containing exactly 'K' distinct inetegers.
//      Return starting & ending index of that subarray.

// {4 2 2 2 3 4 4 3} --> ans = 3_5

//Time : O(N)
//Space : O(N)

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k){
    int n = arr.size();
    int start = 0, end = n;

    unordered_map<int, int> map; // <element, count>

    int i = 0, j = 0;
    int currLen = 0;

    while (j < n){
        //Add the current element to the map
        map[arr[j]]++;
        j++;
        currLen++;
        
        while (map.size() == k){
            if (currLen < end - start + 1){
                start = i;
                end = j - 1;
            }

            //Remove elements from left
            if (map[arr[i]] == 1)
                map.erase(arr[i]);
            else
                map[arr[i]]--;

            i++;
            currLen--;
        }
    }
    
    // Initialize array to store result
    vector<int> ans;

    // There is no subarray with K distinct elements
    if (end == n)
        ans.push_back(-1);
    else {
        //Subarray found
        ans.push_back(start);
        ans.push_back(end);
    }
    
    return ans;
}