#include<bits/stdc++.h>
using namespace std;

//Que.- https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

//Time : O(1)
//Space : O(1)

int minimumDays(int S, int N, int M){
    int sunday = S/7;
    
    int buyingDays = S - sunday;
    int totalFood = S*M;
    int ans = 0;
    
    if(totalFood % N == 0)
        ans = totalFood/N;
    else
        ans = totalFood/N + 1;
        
    if(ans <= buyingDays)
        return ans;
    else
        return -1;
}