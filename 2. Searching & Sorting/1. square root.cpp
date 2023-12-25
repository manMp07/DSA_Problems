#include<iostream>
using namespace std;

//Find the square root of given non negative value x in integer form.
// Time : O(logn)
// Space : O(1)

int main() {
    int num;
    cin >> num;

    int lo = 0;
    int hi = num;
    int ans;

    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (mid * mid <= num){
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}