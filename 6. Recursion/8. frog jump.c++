#include<bits/stdc++.h>
using namespace std;

// Que.- There are N stones. For each 'i' the height of stone 'i' is 'hi'. There is a frog
//       initially on stone-1 and wants to reachs the N'th stone(Frog can go i+1 or i+2).
//       Find the minmum possible total cost incurred before frog reachs to N.
//       Cost for one jump = |hi-hj| where j is the stone to land on.

//       arr = [10, 30, 40, 20]
//       answer = 30

int frogJump(vector <int> arr, int n, int i = 0) {
    if(i == n-1) {
        return 0;
    }
    if(i == n-2) {
        return abs(arr[i] - arr[n-1]);
    }

    int path1 = frogJump(arr, n, i+1) + abs(arr[i] - arr[i+1]);
    int path2 = frogJump(arr,n,i+2) + abs(arr[i] - arr[i+2]);

    return min(path1, path2);
}

int main() {
    vector<int> arr{10, 30, 40, 20};
    int n = arr.size();

    cout << frogJump(arr, n);

    return 0;
}