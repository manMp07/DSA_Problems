#include<bits/stdc++.h>
using namespace std;

// For recursion find these three answer
// 1. Base case
// 2. Assumption
// 3. Self work

// Check if the given array is sorted or not.

bool sortedCheck(int arr[], int n) {
    if(n == 1){
        return true;
    }
    bool restArray = sortedCheck(arr+1, n-1);
    return (arr[0] < arr[1]) && restArray;
}

int main() {
    int n = 7;
    int arr[] = {1,2,3,4,5,6,7};

    cout << sortedCheck(arr, n);

    return 0;
}