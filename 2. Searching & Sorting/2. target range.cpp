#include<iostream>
using namespace std;

// Find the range of given target in sorted array.

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target; cin >> target;

    int ans1 = -1;
    int ans2 = -1;
    int lo = 0, hi = n-1, mid;

    //For upper limit
    while(lo <= hi) {
        mid = hi + (lo-hi)/2;
        if(arr[mid] == target) {
            ans1 = mid;
            hi = mid - 1;
        }
        else if(arr[mid] > target) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    //For lower limit
    lo = 0, hi = n-1;
    while(lo <= hi) {
        mid = lo + (hi - lo)/2;
        if(arr[mid] == target) {
            ans2 = mid;
            lo = mid + 1;
        }
        else if (arr[mid] < target){
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}