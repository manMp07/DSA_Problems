#include<bits/stdc++.h>
using namespace std;

// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least
// one number) which has the maximum sum and return its sum.

long long maxSubarraySum(int arr[], int n){
    long sum = 0;
    long maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        maxSum = max(sum, maxSum);
    }
        
    if(maxSum == 0) {
        maxSum = arr[0];
        for(int i = 0; i < n; i++) {
            if(arr[i] > maxSum) {
                maxSum = arr[i];
            }
        }
    }
    return maxSum;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int array[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << maxSubarraySum(array, n) << endl;

    return 0;
}