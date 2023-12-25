#include<bits/stdc++.h>
using namespace std;

// Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.

// Dutch national falg algo is used for sorting 3 different things.

void sort012(int *arr, int n){
    // Time : O(n)
    // Space : O(1)

    int current = 0;
    int zeroPos = 0;
    int twoPos = n-1;

    while(current <= twoPos) {
        if(arr[current] == 0) {
            swap(arr[current], arr[zeroPos]);
            current++;
            zeroPos++;
        }
        else if(arr[current] == 1) {
            current++;
        }
        else {
            swap(arr[current], arr[twoPos]);
            twoPos--;
        }
    }
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

    sort012(array, n);

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}