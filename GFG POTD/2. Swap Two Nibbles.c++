#include<bits/stdc++.h>
using namespace std;

// DATE : 31 May 2024

//Que.- Given a number n, Your task is to swap the two nibbles and find the resulting number.
//      A nibble is 4-bit aggregation.
//      Ex. N = 150(1001 0110) --> Ans = 105(0110 1001)

int swapNibbles(int n) {
	int left = n & (0b11110000); // store left nibble : 1001 0000
	int right = n & (0b00001111); // store right nibble : 0000 0110
	
	left = left >> 4; // (1001 0000) --> 0000 1001
	right = right << 4; // (0000 0110) --> 0110 0000
	
	return left | right;
}