#include<bits/stdc++.h>
using namespace std;

//Que.- Given two sorted arrays of size m and n respectively, you are tasked with finding
//      the element that would be at the k’th position of the final sorted array.

// Note : Optimal approach is done in "Search & Sorting" Section Que.14.

// Time : O(logn + logm)
// Space : O(logn + logm)

int solve(vector<int> &arr1, vector<int> &arr2, int st1, int en1, int st2, int en2, int k){

    // Base condition.
    if (st1 == en1){
        return arr2[st2 + k];
    }
    if (st2 == en2){
        return arr1[st1 + k];
    }
    int mid1 = (en1 - st1) / 2;
    int mid2 = (en2 - st2) / 2;

    // Recursive calls.
    if ((mid1 + mid2) < k){
        if (arr1[st1 + mid1] > arr2[st2 + mid2]){
            // Rejecting the first half of 'ARR2'.
            return solve(arr1, arr2, st1, en1, st2 + mid2 + 1, en2, k - mid2 - 1);
        }
        else{
            // Rejecting the first half of 'ARR1'.
            return solve(arr1, arr2, st1 + mid1 + 1, en1, st2, en2, k - mid1 - 1);
        }
    }
    else{
        if (arr1[st1 + mid1] > arr2[st2 + mid2]){
            // Rejecting the second half of 'ARR1'.
            return solve(arr1, arr2, st1, st1 + mid1, st2, en2, k);
        }
        else{
            // Rejecting the second half of 'ARR2'.
            return solve(arr1, arr2, st1, en1, st2, st2 + mid2, k);
        }
    }
}

int findKthElement(vector<int> arr1, vector<int> arr2, int k){
    int m = arr1.size();
    int n = arr2.size();

    int st1 = 0;
    int en1 = m;
    int st2 = 0;
    int en2 = n;
    return solve(arr1, arr2, st1, en1, st2, en2, k - 1);
}

// ***Optimal Approach***
// Note : Done in "Search & Sorting" Section Que.14.