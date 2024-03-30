#include<iostream>
using namespace std;

//Que.- You are given two integers 'A' and 'B'. Give the number of bits that need to be
//      flipped in ‘A’ to obtain ‘B’.

//Time : O(log(A^B))
//Space : O(1)

int flipBits(int A, int B){
    int ans  = A ^ B;

    // count set bits in ans    
    int count = 0;
    while(ans != 0){
        ans = ans & (ans-1);
        count++;
    }

    return count;
}