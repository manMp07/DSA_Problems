#include<bits/stdc++.h>
using namespace std;

// aaaabbbcddd

string encode(string str) {
    int t1 = 0;
    int t2 = 0;

    char s1 = '0'; //010101010101...
    char s2 = '1'; //101010101010...
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == s1) {
            t2++;
        }
    }
}

int main() {
    
}