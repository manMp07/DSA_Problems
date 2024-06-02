#include<bits/stdc++.h>
using namespace std;

// DATE : 29 May 2024

//Que.- Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the
//      beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek
//      always starts the game. The player who picks the last coin wins the game. The task
//      is to determine whether Geek will win the game or not if both players play optimally.

int findWinner(int n, int x, int y) {
    vector<int> dp(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        bool op1 = dp[i-1];
        bool op2 = true, op3 = true;
        
        if(i-x >= 0)
            op2 = dp[i-x];
        if(i-y >= 0)
            op3 = dp[i-y];
            
        // if any of the option can loss, means I can win on that option.
        if(op1 == 0 || op2 == 0 || op3 == 0)
            dp[i] = 1;
    }
    
    return dp[n];
}