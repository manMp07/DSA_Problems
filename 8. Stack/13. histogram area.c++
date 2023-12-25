#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Que.- Given an array of integers heights representing the histogram's bar height where
//      the width of each bar is 1, return the area of the largest rectangle in the
//      histogram.

//Time : O(N)
//Space : O(1)

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
        while(s.top() != -1 && arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    
    return ans; 
}

int largestRectangle(vector<int> &heights) {
    int n= heights.size();
        
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = -1;

    for(int i=0; i<n; i++) {
        int l = heights[i];
            
        if(next[i] == -1) {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int curr_area = l * b;
        area = max(area, curr_area);
    }

    return area;
}