#include<bits/stdc++.h>
using namespace std;

//Que.- You are given an array in which every element appears thrice accept one. You need to
//      find the element that appears only once.

//Time : O(32*N); In all cases
//Space : O(1)

int elementThatAppearsOnce(vector<int> arr) {
	int ans = 0;
	for(int j = 0; j < 32; j++){
		int setBits = 0;
		for(int i = 0; i < arr.size(); i++)
			if(arr[i] & (1 << j))
				setBits++;
		
		if(setBits % 3 == 1)
			ans = ans | (1 << j);
	}

	return ans;
}

//Time : O(N*logN); This is better than O(32*N), as N needs to be 2^32(~10^9) to get O(32*N), but N is at max 10^4.
//Space : O(1)

int elementThatAppearsOnce(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();

	for(int i = 1; i < n; i = i+3)
		if(arr[i-1] != arr[i])
			return arr[i-1];

	return arr[n-1];
}

//Time : O(N); For more understanding watch striver's video solution.
//Space : O(1)

int elementThatAppearsOnce(vector<int> arr) {
	int ones = 0;
	int twos = 0;

	for(int i = 0; i < arr.size(); i++){
		ones = (ones ^ arr[i]) & (~twos);
		twos = (twos ^ arr[i]) & (~ones);
	}

	return ones;
}