//multiplication
#include<iostream>
using namespace std;

int fact(int n) {
    int ans = 1;
    for(int i = 1; i<= n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int a [n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                a[i][j] = 1;
            }
            else if(j == i) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = a[i-1][j] + a[i-1][j-1];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
        }cout << endl;
    }
    return 0;
}