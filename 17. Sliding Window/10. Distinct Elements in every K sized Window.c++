#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array of integers and a number K. Find the count of distinct
//      elements in every window of size K in the array.

//Time : O(N)
//Space : O(K)

vector<int> countDistinctElements(vector<int> &arr, int k) {
	unordered_map<int, int> mp;

    for(int i = 0; i < k; i++)
        mp[arr[i]]++;

    int i = 0, j = k;
    vector<int> ans;
    while(j < arr.size()) {
        ans.push_back(mp.size());
        mp[arr[j]]++;
        j++;

        if(mp[arr[i]] == 1)
            mp.erase(arr[i]);
        else
            mp[arr[i]]--;
        i++;
    }
    ans.push_back(mp.size());

    return ans;
}