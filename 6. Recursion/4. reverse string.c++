#include<iostream>
using namespace std;

// Reverse a string using recursion

void reverse(string s){
    if(s.length() == 0) { // base case
        return;
    }
    string ros = s.substr(1); // from index 1 to last index
    reverse(ros);
    cout << s[0];
}

string reverse1(string s) {
    if(s.length() == 0) {
        return "";
    }
    string ans = reverse1(s.substr(1));
    char ch = s[0];
    return ans+ch;
}

int main() {
    string str = "binod";
    int n = str.size();

    cout << reverse1(str);

    return 0;
}