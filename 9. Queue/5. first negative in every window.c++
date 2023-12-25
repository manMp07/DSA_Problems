#include<bits/stdc++.h>
using namespace std;

//Que.- Given array of size 'N' and integer 'K'. Task is to find the first negative
//      element in every window of length 'K'. If there is no negative element in
//      window, then print 0 for that window.
//      Ex.- {-8, 2, 3, -6, 10}(k=2) --> {-8, 0, -6, -6}.


// Time : O(N)
// Space : O(K)
vector<int> firstNegative(vector<int> arr, int n, int k) {
	queue<int> q;
	vector<int> ans;

	// process first window of K size
	for(int i = 0; i < k; i++) {
		if(arr[i] < 0) {
			q.push(i);
		}
	}
	
	//store answer of first K sized window
	if(q.empty()) {
		ans.push_back(0);
	}
	else{
		ans.push_back(arr[q.front()]);
	}

	//process for remaining windows
	for(int i = k; i < n; i++) {
		//removal
		if(!q.empty() && i-q.front() >= k) {
			q.pop();
		}

		//addition
		if(arr[i] < 0) {
			q.push(i);
		}

		if(q.empty()) {
			ans.push_back(0);
		}
		else{
			ans.push_back(arr[q.front()]);
		}
	}

	return ans;
}

//Find optimal approach