#include<bits/stdc++.h>
using namespace std;

// DATE : 02 June 2024

//Que.- Given a list s that initially contains only a single value 0. There will be q
//      queries of the following types:
//      0 x: Insert x in the list
//      1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR
//      operator)
//      Return the sorted list after performing the given q queries.


/***Pre-requisite : "Difference Array" Technique***/
// Time : O(Q*logQ)
// Space : O(Q) ; without ans

vector<int> constructList(int q, vector<vector<int>> &queries) {
    vector<int> ans;
    ans.push_back(0);
    vector<int> diff(q+1, 0);
    
    // O(Q)
    for(int i = 0; i < q; i++){
        int type = queries[i][0];
        int x = queries[i][1];
        
        if(type == 0)
            ans.push_back(x);
        else {
            diff[0] = diff[0] ^ x;
            diff[ans.size()] = diff[ans.size()] ^ x;
        }
    }
    
    // O(Q)
    for(int i = 1; i <= q; i++)
        diff[i] = diff[i]^diff[i-1];
    
    // O(Q)
    for(int i = 0; i < ans.size(); i++)
        ans[i] = ans[i]^diff[i];
    
    // O(Q*logQ)
    sort(ans.begin(), ans.end());
    
    return ans;
}

/***Traversing from backwords in the queries***/
// Time : O(Q*logQ)
// Space : O(1) ; without ans

vector<int> constructList(int q, vector<vector<int>> &queries) {
    vector<int> ans;
    int Xor = 0;
    
    for(int i = q-1; i >= 0; i--){
        if(queries[i][0])
            Xor = Xor ^ queries[i][1];
        else
            ans.push_back(queries[i][1] ^ Xor);
    }
    
    ans.push_back(0 ^ Xor); // initially list has 0.
    sort(ans.begin(), ans.end());
    
    return ans;
}