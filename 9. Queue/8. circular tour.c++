#include<bits/stdc++.h>
using namespace std;

//Que.- Suppose there is a circle. There are N petrol pumps on that circle. You will be
//      given two sets of data.
//      1. The amount of petrol that every petrol pump has.
//      2. Distance from that petrol pump to the next petrol pump.
//      Find a starting point where the truck can start to get through the complete
//      circle without exhausting its petrol in between.
//      Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Time : O(N)
// Space : O(1)

int firstCircularTour(vector<int>& petrol, vector<int>& distance, int n){
	long long int dificit = 0;
	long long int balance = 0;
	int start = 0;

	for(int i = 0; i < n; i++) {
		balance += petrol[i] - distance[i];

		if(balance < 0) {
			dificit += balance;
			balance = 0;
			start = i+1;
		}
	}

	if(balance + dificit >= 0) {
		return start;
	}
	else {
		return -1;
	}
}
