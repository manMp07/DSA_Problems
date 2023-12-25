#include<bits/stdc++.h>
using namespace std;

//Que.- Given two array, both represent max heap. Your task is to find the Max-Heap
//      obtained by merging these two arrays.

// Time : O(N+M)
// Space : O(N+M)

void heapify(vector<int> &arr, int i, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;

    if(left < n && arr[largest] < arr[left])
        largest = left;
    if(right < n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // step1 : merge both array
    vector<int> ans;
    for(int i = 0; i < n; i++)
        ans.push_back(arr1[i]);
    for(int i = 0; i < m; i++)
        ans.push_back(arr2[i]);
    
    // step2 : build heap
    for(int i = ans.size()/2 - 1; i >= 0; i--) {
        heapify(ans, i, n+m);
    }

    return ans;
}