#include<bits/stdc++.h>
using namespace std;

// Find peak index in mountain array of length grater than 3.

int multiPeakElement(vector <int> &a) {
    int n = a.size();
    if( n == 1) {
        return 0;
    }
    int lo = 0;
    int hi = n - 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(mid == 0) {
            if(a[mid] > a[mid + 1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(mid == n-1) {
            if(a[mid] > a[mid-1]) {
                return n-1;
            }
            else {
                return n-2;
            }
        }
        else {
            if(a[mid] > a[mid + 1] && a[mid] > a[mid-1]) {
                return mid;
            }
            else if(a[mid] > a[mid-1]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector <int> arr;
    int n; cin >> n;
    while(n--) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << multiPeakElement(arr) << endl;

    return 0;
}