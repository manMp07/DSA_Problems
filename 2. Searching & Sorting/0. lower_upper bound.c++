#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,2,4,5,6,7,8,9,13,15};
    int x = 10;
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // arr[lb] >= x
    cout << "Lower Bound : " << lb << endl;

    int up = upper_bound(arr.begin(), arr.end(), x) - arr.begin(); // arr[up] > x
    cout << "Upper Bound : " << lb << endl;
}