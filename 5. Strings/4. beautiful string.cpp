#include <bits/stdc++.h>
using namespace std;

//Que.- For given any string containing only 0s or 1s, make a beautiful string by performing
//      some operation.
//      (A binary string is considered as beautiful string if it contains alternating 0s & 1s)
//      In one operation you can convert '0' into '1' and vise versa.
//      Your task is to find minimum number of operation to convert into beautiful string.

int makeBeautiful(string str) {
    // 'T1' denotes the difference between values at indices in 'STR' and the possible beautiful string starting with 0 
    // 'T2' denotes the difference between values at indices in 'STR' and the possible beautiful string starting with 1
    // 'S1' and 'S2' denote the expected value at index 'i' in both of the possible beautiful strings 
    int t1 = 0, t2 = 0;
    char s1 = '0', s2 = '1';

    // s1 = 01010101010.....
    // s2 = 10101010101.....

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == s1) {
            t2++;
        }

        else {
			t1++;
        }
        
        // If 'S1' == '0' then make it 1 and vise versa do the same for 'S2'
        if (s1 == '1') {
            s1 = '0';
            s2 = '1';
        }
        else {
            s1 = '1';
            s2 = '0';
        }
    }
    
    // Return the minimum of 'T1' and 'T2'
    return min(t1, t2);
}

int main() {
    string s;
    getline(cin, s);
    int answer = makeBeautiful(s);
    cout << answer << endl;

    return 0;
}