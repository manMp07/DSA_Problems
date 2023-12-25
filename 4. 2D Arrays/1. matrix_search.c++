#include<iostream>
#include<climits>
using namespace std;

// Search an element in nXm matrix where all rows & columns are sorted. 

int main () {
    int n,m;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int key;
    cin >> key;

    bool found = false;
    
    int r = 0, c = m-1;
    while(r < n && c >= 0) {
        if(arr[r][c] > key) {
            c--;
        }
        else if(arr[r][c] < key) {
            r++;
        }
        else {
            found = true;
            break;
        }
    }

    if(found) {
        cout << "Element found at " << r << " " << c << endl;
    }
    else{
        cout << "Element does not exist" << endl;
    }
    
    return 0;
}