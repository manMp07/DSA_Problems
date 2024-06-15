#include<bits/stdc++.h>
using namespace std;

// DATE : 15 June 2024

//Que.- There is a standard numeric keypad on a mobile phone. You can only press the
//      current button or buttons that are directly up, left, right, or down from it
//      (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements
//      and pressing the bottom row corner buttons (* and #) are prohibited.
//      Given a number n, find the number of possible unique sequences of length n that
//      you can create by pressing buttons. You can start from any digit.

int mat[4][3] = {{1,2,3},
                 {4,5,6},
                 {7,8,9},
                 {-1,0,-1}};
                    
long long dp[10][26];

long long solve(int n, int i, int j){
    if(n == 1)
        return 1;
        
    if(dp[mat[i][j]][n] != -1)
        return dp[mat[i][j]][n];
        
    long long currAns = solve(n-1, i, j);
    
    if(i-1 >= 0) //up
        currAns += solve(n-1, i-1, j);
        
    if(i+1 < 4 && mat[i+1][j] != -1) //down
        currAns += solve(n-1, i+1, j);
        
    if(j-1 >= 0 && mat[i][j-1] != -1) // left
        currAns += solve(n-1, i, j-1);
        
    if(j+1 < 3 && mat[i][j+1] != -1) // right
        currAns += solve(n-1, i, j+1);
        
    return dp[mat[i][j]][n] = currAns;
}

long long getCount(int n) {
    memset(dp, -1, sizeof(dp));
    
    long long ans = 0;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i][j] != -1)
                ans += solve(n, i, j);
        }
    }
    
    return ans;
}