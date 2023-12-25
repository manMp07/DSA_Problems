#include<bits/stdc++.h>
using namespace std;

// Check if the target is present in the given rotated sorted array which contain duplicates.

bool rotatedSearch(int arr[], int n, int target) {
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (hi+lo)/2;
        if(arr[mid] == target) {
            return true;
        }
        // if lo, mid, hi is same we can't conclude anything
        if(arr[lo] == arr[mid] && arr[mid] == arr[hi]) {
            hi = hi - 1;
            lo = lo + 1;
            continue;   
        }
        if(arr[lo] <= arr[mid]) {
            if(arr[lo] <= target && target <= arr[mid]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        else {
            if(arr[mid] <= target && target <= arr[hi]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    int array[] = {3,3,1,2,3,3,3,3,3};
    int k = 2;
    int n = sizeof(array);

    cout << rotatedSearch(array, n, k);

    return 0;
}