#include<bits/stdc++.h>
using namespace std;

// For given array, you are supposed to find all the elements that occurs more than n/3 times.

vector<int> majorityElementII(vector<int> &arr){
    // Time : O(n)
    // Space : O(n)
    int n = arr.size();
    vector<int> majorityElement;
    int firstCandidate = 0, secondCandidate = 0;

    int firstCount = 0, secondCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == firstCandidate) {
            firstCount++;
        }
        else if(arr[i] == secondCandidate) {
            secondCount++;
        }
        else if(firstCount == 0) {
            firstCandidate = arr[i];
            firstCount = 1;
        }
        else if(secondCount == 0) {
            secondCandidate = arr[i];
            secondCount = 1;
        }
        else {
            firstCount--;
            secondCount--;
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
    cin >> n;

    vector <int> array;
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector <int> answer = majorityElementII(array);

    for(auto i : answer) {
        cout << answer[i] << " ";
    }

    return 0;
}