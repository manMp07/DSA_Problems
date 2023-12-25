#include<bits/stdc++.h>
using namespace std;

//Que.- Given a binary matrix M of size n X m. Find the maximum area of a rectangle
//      formed only of 1s in the given matrix.

// Time : O(N * M)
// Space : O(M)

vector<int> nextSmallerElement(vector<int> arr, int n) {
	stack<int> s;
	s.push(-1);

	vector<int> ans(n);

	for(int i = n-1; i >= 0; i--) {
		while(s.top() != -1 && arr[s.top()] >= arr[i]) {
			s.pop();
		}

		ans[i] = s.top();
		s.push(i);
	}

	return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
	stack<int> s;
	s.push(-1);

	vector<int> ans(n);

	for(int i = 0; i < n; i++) {
		while(s.top() != -1 && arr[s.top()] >= arr[i]) {
			s.pop();
		}

		ans[i] = s.top();
		s.push(i);
	}

	return ans;
}

// Histogram
int largestRectangle(vector<int> &arr) {
	int n = arr.size();

	vector<int> next(n);
	next = nextSmallerElement(arr, n);

	vector<int> prev(n);
	prev = prevSmallerElement(arr, n);

	int area = -1;

	for(int i = 0; i < n; i++) {
		int l = arr[i];

		if(next[i] == -1) {
			next[i] = n;
		}
		int b = next[i] - prev[i] - 1;

		int curr_area = l * b;

		area = max(area, curr_area);
	}
	return area;
}

//lec.138
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
    int ans = -1e9;
    vector<int> histogram(mat[0].size(), 0);

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            if(mat[i][j] == 1)
                histogram[j]++;
            else
                histogram[j] = 0;
        }
        ans = max(ans, largestRectangle(histogram));
    }

    return ans;
}