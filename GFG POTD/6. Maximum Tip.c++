#include<bits/stdc++.h>
using namespace std;

// DATE : 11 June 2024

//Que.- In a restaurant, two waiters, A and B, receive n orders per day, earning tips as
//      per arrays arr[i] and brr[i] respectively. If A takes the ith order, the tip is
//      arr[i] rupees; if B takes it, the tip is brr[i] rupees.
//      To maximize total tips, they must distribute the orders such that:
//      A can handle at most x orders
//      B can handle at most y orders
//      Given that x + y ≥ n, all orders can be managed by either A or B. Return the
//      maximum possible total tip after processing all the orders.

/*** Using DP ***/
// Time : O(N*X*Y)
// Space : O(N*X*Y)

/*** Greedy ***/
// Time : O(N*logN)
// Space : O(N)

long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int, pair<int, int>>> diff(n);
        
        for(int i = 0; i < n; i++)
            diff[i] = {abs(arr[i] - brr[i]), {arr[i], brr[i] }};
            
        sort(diff.rbegin(), diff.rend());
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(x == 0)
                ans += diff[i].second.second;
                
            else if(y == 0)
                ans += diff[i].second.first;
                
            else if(diff[i].second.first > diff[i].second.second){
                ans += diff[i].second.first;
                x--;
            }
            
            else{
                ans += diff[i].second.second;
                y--;
            }
        }
        
        return ans;
    }