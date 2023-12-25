#include<iostream>
#include<climits>

using namespace std;

// Que.1 - Find the subarray in an array which has maximum sum.
int kadane(int a[], int n);

// Que.2 - Find the circular subarray  in an array which has maximum sum.

// Que.3 - Check if there exists exact two elements in an array such that their sum is
//         equal to given K.
bool pairSum(int a[], int n, int k);

// Ans.2
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    
    int wrapSum;
    int nonwrapSum = kadane(arr, n);
    int totalsum = 0;
    for(int i = 0; i<n; i++) {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapSum = totalsum - (-kadane(arr,n));

    cout << max(wrapSum, nonwrapSum);

    return 0;
}

int kadane(int a[], int n) {
    int ans = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum < 0) {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    return ans;
}

bool pairSum(int a[], int n, int k) {
    int high = 0;
    int low = n-1;

    while(high < low) {
        if(a[low] + a[high] == k) {
            cout << low << " " << high << endl;
            return true;
        }
        else if(a[low] + a[high] > k) {
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}