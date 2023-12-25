#include<iostream>
using namespace std;

// Find the first and last occurance of a given number in an array.

int lastOcc(int arr[], int n, int i, int key) {
    if(i == n) {
        return -1;
    }

    int restArray = lastOcc(arr, n, i+1, key);
    if(restArray != -1) {
        return restArray;
    }
    
    if(arr[i] == key) {
        return i;
    }
    return -1;
}

int firstOcc(int arr[], int n, int i, int key) {
    if(i == n) {
        return -1;
    }
    if(arr[i] == key) {
        return i;
    }
    return firstOcc(arr, n, i+1, key);
}

int main() {
    int n = 7;
    int arr[] = {4,2,1,2,5,2,7};

    cout << firstOcc(arr,n,0,2) << endl;
    cout << lastOcc(arr,n,0,2) << endl;
    
    return 0;
}