#include<bits/stdc++.h>
using namespace std;

// Que.- You are given a sorted array of 'N' integers. You have to generate the power set 
//       of this array.

void solve(vector<int> arr, int index, vector<int> output, vector<vector<int>>& ans) {
    if(index >= arr.size()) {
        ans.push_back(output);
        return;
    }
    
    //exclusion
    solve(arr, index+1, output, ans);

    //inclusion
    int element = arr[index];
    output.push_back(element);
    solve(arr, index+1, output, ans);
}

vector<vector<int>> powerSet(vector<int>arr){
    vector<vector<int>> ans;
    vector<int> output;
    solve(arr, 0, output, ans);
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    vector<vector<int>> ans = powerSet(arr);

    for(auto x : ans) {
        for(auto y : x) {
            cout << y << " ";
        }cout << endl;
    }

    return 0;
}