#include<iostream>
#include<climits>
using namespace std;

// Que.- Find the row which has maximum number of 1's in 2D boolean array where all
//       rows are sorted.

int main() {
    int n,m;
    cin >> n >> m;

    int arr[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int leftmost1 = -1;
    int ans = -1;
    int j = m - 1;
    while(j>=0 && arr[0][j] == 1) {
        leftmost1 = j;
        ans = 0;
        j--;
    }

    for(int i = 1; i < n; i++) {
        while(j >= 0 && arr[i][j] == 1) {
            leftmost1 = j;
            j--;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}