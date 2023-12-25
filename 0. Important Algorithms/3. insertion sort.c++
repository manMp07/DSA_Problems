#include<bits/stdc++.h>
using namespace std;

// Sort given array using insertion sort algorithm.

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i-1;
        while(arr[j] > current && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
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

    insertionSort(array, n);

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}