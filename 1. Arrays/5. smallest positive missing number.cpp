#include<bits/stdc++.h>
using namespace std;

//You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

int missingNumber(int arr[], int n) {
    //Conversion of the array
    int i = 0;
    while(i < n){
        if(arr[i] <= 0 || arr[i] > n || arr[i] == i+1)
            i++;
        else
            swap(arr[i], arr[arr[i]-1]);
    }

    // Searching for the smallest positive integer missing in the array
    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            return i+1;
        }
    }

    // All the integer from 1 to n were present in the array
    // that means the answer should be n+1;
    return n+1;
}

int main() {
    int n; cin >> n;
    int arr[n]; //3,4,7,1
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << missingNumber(arr, n) << endl;

    return 0;
}