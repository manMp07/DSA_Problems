#include<iostream>
using namespace std;

//Que1.- Swap two numbers without using third variable
void swapNumber(int &a, int &b) {
	a = a^b;
    b = a^b; // (a^b)^b
    a = a^b; // (a^b)^(a)
}

//Que2.- Check if ith bit is set or not in the given number N.
bool isIthBitSet(int n, int i){
    return n & (1 << i);
}

//Que3.- Set ith Bit.
int setIthBit(int n, int i){
    return n | (1 << i);
}

//Que4.- Clear ith Bit.
int clearIthBit(int n, int i){
    return n & ~(1 << i);
}

//Que5.- Toggle ith Bit.
int toggleIthBit(int n, int i){
    return n ^ (1 << i);
}

//Que6.- Remove Last Set Bit
int removeLastSetBit(int n){
    return n & (n-1);
}

//Que7. Check is the number is power of 2?
bool isPowerOfTwo(int n){
    return !(n & (n-1));
}

//Que8.- Count the number of set bits
int countSetBit(int n){
    /*int cnt = 0;
    while(n != 0){
        cnt += n & 1;
        n >> 1;
    }
    return cnt;*/

    int count = 0;
    while(n != 0){
        n = n & (n-1);
        count++;
    }
    return count;
}