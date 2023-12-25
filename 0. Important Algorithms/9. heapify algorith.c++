#include<iostream>
using namespace std;

// Converting an array into maxHeap.

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left])
        largest = left;
    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int arr[6] = {-1, 3, 4, 5, 1, 6}; int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the array : ";
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}