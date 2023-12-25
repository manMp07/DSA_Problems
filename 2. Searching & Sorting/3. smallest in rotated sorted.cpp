#include <iostream>
using namespace std;

// Find the index of smallest element in rotated sorted array.

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int lo = 0, hi = n-1, mid;

    if(arr[lo] > arr[hi]) {
        while(lo <= hi) {
            mid = lo + (hi - lo)/2;
            if(arr[mid] > arr[mid+1])
                cout << mid+1 << endl; break;
            if(arr[mid-1] > arr[mid])
                cout << mid << endl; break;
                
            if(arr[mid] < arr[lo]) {
                hi = mid - 1;
            }
            else { // arr[mid] > arr[lo]
                lo = mid + 1;
            }
        }
    }
    else {
        cout << lo << endl;
    }

    return 0;
}