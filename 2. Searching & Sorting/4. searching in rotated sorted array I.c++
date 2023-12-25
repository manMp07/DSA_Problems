#include<bits/stdc++.h>
using namespace std;

// In rotated sorted array, find the index of given target(all elements are unique).

int targetIndex(vector <int> arr, int target, int n) {
    int lo = 0;
    int hi = n - 1;
    while(lo <= hi) {
        int mid = (hi + lo)/2;
        if(arr[mid] == target) {
            return mid;
        }
        // if left part is sorted
        if(arr[lo] <= arr[mid]) {
            if(arr[lo] <= target && target <= arr[mid]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        // else right part is sorted
        else{
            if(arr[mid] <= target && target <= arr[hi]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}


int main () {
    vector <int> arr = {7,8,9,1,2,3,4,5,6};
    int k = 5;
    int size = 9;

    cout << targetIndex(arr, k, size) << endl;

    return 0;
}