#include<bits/stdc++.h>
using namespace std;

// Remove concecutive duplicates from string.

string removeDup(string s) {
    if(s.length() == 0) {
        return "";
    }

    char ch = s[0];

    string ans = removeDup(s.substr(1));

    if(ans[0] == ch) {
        return ans;
    }
    else{
        return ch+ans;
    }
}

string removeDup2(string s) {
    int n = s.length();
    if(n < 2) {
        return s;
    }
    if(s[n-1] == s[n-2]) {
        s.pop_back();
        return removeDup2(s);
    }
    else {
        char last = s.back();
        s.pop_back();
        return removeDup2(s) + last;
    }
}

int main() {
    string s = "aaaabbbbcddeeee";
    cout << removeDup2(s);

    return 0;
}