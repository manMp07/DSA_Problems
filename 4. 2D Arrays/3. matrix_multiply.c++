#include<iostream>
using namespace std;

void transpose(int n, int arr[][3]);

int main() {
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2];
    int m2[n2][n3];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            cin >> m1[i][j];
        }
    }
    
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < n3; j++) {
            cin >> m2[i][j];
        }
    }

    int ans[n1][n3];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n3; j++) {
            ans[i][j] = 0;
        }
    }

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            for(int k = 0; k < n3; k++) {
                ans[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n3; j++) {
            cout << ans[i][j] << "   ";
        }
        cout << "\n";
    }

    return 0;
}

void transpose(int n, int arr[][3]) {
    //transpose of nxn matrix.
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            //swap
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(int i = 0; i< n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}