#include<bits/stdc++.h>
using namespace std;
#define pi 3.14 // this is called macros

// Sort given array using selection sort algorithm.

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]); 
            }
        }
    }
}

void selectionSort2(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
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

    selectionSort2(array, n);

    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}