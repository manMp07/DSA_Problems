//Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

#include<bits/stdc++.h>
using namespace std;

int mooreVoting(int arr[], int n) {
    int result = arr[0];
    int count = 1;

    for(int i = 1; i < n; i++) {
        if(count == 0) {
            result = arr[i];
            count = 1;
        }
        else if(arr[i] == result) {
            count++;
        }
        else {
            count--;
        }
    }

    count = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == result) {
            count++;
        }

        if(count > n/2) {
            return arr[i];
        }
    }

    return -1;
}

vector<int> majorityElementII(vector<int> &arr){
    int n = arr.size();
    vector<int> majorityElement;
    int firstCandidate = 0, secondCandidate = 0;

    int firstCount = 0, secondCount = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] == firstCandidate) {
            firstCount = firstCount + 1;
        }

        else if (arr[i] == secondCandidate) {
            secondCount = secondCount + 1;
        }

        else if (firstCount == 0) {
            firstCandidate = arr[i];
            firstCount = 1;
        }

        else if (secondCount == 0) {
            secondCandidate = arr[i];
            secondCount = 1;
        }

        else{
            firstCount = firstCount - 1;
            secondCount = secondCount - 1;
        }
    }

    firstCount = 0;
    secondCount = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] == firstCandidate){
            firstCount = firstCount + 1;
        }

        else if (arr[i] == secondCandidate){
            secondCount = secondCount + 1;
        }
    }

    if (firstCount > n/3){
        majorityElement.push_back(firstCandidate);
    }

    if (secondCount > n/3){
        majorityElement.push_back(secondCandidate);
    }

    return majorityElement;

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

    cout << mooreVoting(array, n) << endl;

    return 0;
}