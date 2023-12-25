#include<iostream>
using namespace std;

// Find the length of contiguos(difference between every two elements should be equal)
// arithmetic subarray that has the maximum length.

int main(){
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 2;
    int pd = a[1] - a[0]; //previous difference
    int current = 2;

    for(int i = 2; i < n; i++) {
        if(a[i] - a[i-1] == pd) {
            current++;
        }
        else{
            pd = a[i] - a[i-1];
            current = 2;
        }
        ans = max(ans, current);
    }

    cout << ans << endl;

    return 0;
}