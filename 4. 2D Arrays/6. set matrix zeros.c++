#include<bits/stdc++.h>
using namespace std;

// For given N*M matrix, if an element is 0, set its entire row and column to 0's.

void setZeros1(vector<vector<int>> &arr) {
    // Time : O(n*m*(n+m))
    // Space : O(1)

	int n = arr.size();
	int m = arr[0].size();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 0) {
				arr[i][j] = -1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == -1) {
				arr[i][j] = 0;
				for(int k = 0; k < m; k++) {
					if(arr[i][k] != -1) {
						arr[i][k] = 0;
					}
				}
				for(int k = 0; k < n; k++) {
					if(arr[k][j] != -1) {
						arr[k][j] = 0;
					}
				}
			}
		}
	}
}

void setZeros2(vector<vector<int>> &arr) {
    // Time : O(n*m)
    // Space : O(n+m)

	int n = arr.size();
	int m = arr[0].size();

	unordered_set<int> row;
	unordered_set<int> column;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 0) {
				row.insert(i);
				column.insert(j);
			}
		}
	}
	for(auto x : row) {
		for(int j = 0; j < m; j++) {
			arr[x][j] = 0;
		}
	}

	for(int i = 0; i < n; i++) {
		for(auto y : column) {
			arr[i][y] = 0;
		}
	}

	return;
}

void setZeros3(vector<vector<int>> &arr) {
    // Time : O(n*m)
    // Space : O(1)

	int n = arr.size();
	int m = arr[0].size();
	
	// Declaring two boolean variables firstColZero and firstRow.
	bool firstCol = false, firstRow = false;
	
	// Setting firstCol to true if any element in first column is zero.
	for(int i = 0; i < n; i++) {
		if(arr[i][0] == 0) {
			firstCol = true;
			break;
		}
	}
	
	// Setting firstRow to true if any element in first row is zero.
	for(int j = 0; j < m; j++) {
		if(arr[0][j] == 0) {
			firstRow = true;
			break;
		}
	}
	
	// Setting values for each row and column to be zero or not.
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(arr[i][j] == 0) {
				arr[i][0] = arr[0][j] = 0;
			}
		}
	}
	
	// If any element of first row is zero then that complete column should be zero and vice-versa.
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(arr[i][0] == 0 || arr[0][j] == 0) {
				arr[i][j] = 0;
			}
		}
	}
	
	// Setting first column to zero if firstCol is true.
	if(firstCol) {
		for(int i = 0; i < n; i++) {
			arr[i][0] = 0;
		}
	}
	
	// Setting first row to zero if firstRow is true.
	if(firstRow) {
		for(int j = 0; j < m; j++) {
			arr[0][j] = 0;
		}
	}
}

int main() {
    int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> matrix[n][m];
    
    for(int i = 0; i < n; i++) {
        vector<int> row;
        for(int j = 0; j < m; j++) {
            int value;
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    setZeros1(matrix[n][m]);

    return 0;
}