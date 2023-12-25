#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Que.- You are given the array of integers of length N. Your task is to find next 
//      smaller element for each of the array element.
//      Next smaller element for an array element is the first element to the right of 
//      that element which is strictly less that that element.
//      If not found, print -1 for that element.
//      Ex.- 2 1 4 3 --> 1 -1 3 -1

vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    for(int i = n-1; i >= 0; i--) {
        while(s.top() != -1 && arr[i] <= s.top()) {
            s.pop();
        }

        //ans is on top of stack
        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}