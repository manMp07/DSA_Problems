#include<bits/stdc++.h>
using namespace std;

// Sort given array using bubble sort algorithm.

void bubbleSort(int arr[], int n) {
    for(int count = 0; count < n-1; count++){
        for(int j = 0; j < n-count-1; j++) {
            if(arr[j+1] < arr[j]) {
                swap(arr[j+1], arr[j]);
            }
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

    bubbleSort(array, n);

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}