#include<iostream>
using namespace std;

// Que.- An array is giving information about the number of visitors for N consicutive
//       days. A day is record breaking day if it setisfies both the following
//       conditions:
//       1. The number of visitors on the day is stricly larger than the number of
//          visitors on each of the previous day.
//       2. Either it is the last day or the number of visitors on the day is stricly
//          larger than the number of visitors on the followig day.
//       ex. 2,5,3,7,3,4,9 => Here three record-breaking days considered...5,7,9

int main() {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n == 1){
        cout << "1" << endl;
        return 0; 
    }

    a[n] = 0;
    int maximum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > maximum && a[i] > a[i+1]) {
            ans++;
        }
        maximum = max(maximum, a[i]);
    }
    cout << ans << endl;

    return 0;
}