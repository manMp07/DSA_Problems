#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two numbers 'L' and 'R'. Find the XOR of the elements in the range [L, R].

//Time : O(1)
//Space : O(1)

int nXOR(int n){
    // It Gives XOR of 1 to N.
    if(n % 4 == 1)  return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
    if(n % 4 == 0)  return n;
}

int findXOR(int L, int R){
    return nXOR(L-1) ^ nXOR(R);
}