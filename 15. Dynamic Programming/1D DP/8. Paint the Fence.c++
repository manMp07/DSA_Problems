#include <bits/stdc++.h>
using namespace std;

//Kuch Pata nhi chala iss qustion me :)

//Que.- Given a fence with n posts and k colors, find out the number of ways of
//      painting the fence such that at most 2 adjacent posts have the same color.

/***Recursion***/

int solve(int n, int k) {
    if(n == 1)
        return k;
    if(n == 2)
        return (k + k*(k-1));

    return solve(n-1, k)*(k-1) + solve(n-2, k)*(k-1);
}

int numberOfWays(int n, int k) {
    int ans = solve(n, k);
    return ans;
}