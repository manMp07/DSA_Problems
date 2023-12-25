#include<iostream>
using namespace std;

// Que.- Given an unsorted array A of size N of non-negtive integers, find a continuous
//       subarray which adds to a given number S.

int main() {
    int n,s;
    cout << "Enter S: " << endl;
    cin >> s;
    cout << "Enter total number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int  i=0, j=0, sum=0;

    while(j < n && sum + a[j] <= s) {
        sum += a[j++];
    }

    if(sum == s) {
        cout << i+1 << " " << j << endl;
        return 0;
    }

    while(j < n) {
        sum += a[j];
        while(sum > s) {
            sum -= a[i];
            i++;
        }
        if(sum == s) {
            break;
        }
        j++;
    }

    cout << i+1 << " " << j+1 << endl;

    return 0;
}