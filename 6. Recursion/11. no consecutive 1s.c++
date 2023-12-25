#include<bits/stdc++.h>
using namespace std;

// Que.- For given integer 'N', generate all binary string of length 'N' such that there
//       are no consecutive 1's in the string.

void generateStringhelper(int N, int i, string &str, vector<string> &ans) {
    if(i == N) {
        ans.push_back(str);
        return;
    }

    //If previous character is '1' then we put Only 0 at end of string
    if(str[i-1] == '1') {
        str[i] = '0';
        generateStringhelper(N, i+1, str, ans);
    }

    //If previous character is '0' than we put Both '1' and '0' at end of string
    if(str[i-1] == '0') {
        str[i] = '0';
        generateStringhelper(N, i+1, str, ans);
        str[i] = '1';
        generateStringhelper(N, i+1, str, ans);
    }
}

vector <string> generateString(int N) {
    vector<string> ans;
    if(N == 0) {
        return ans;
    }

    string s(N, '0');

    //First character is 0
    s[0] = '0';
    generateStringhelper(N, 1, s, ans);

    //First character is 1
    s[0] = '1';
    generateStringhelper(N, 1, s, ans);

    return ans;
}

int main() {
    int N;
    cin >> N;

    vector<string> ans = generateString(N);

    for(auto x:ans) {
        cout << x << " ";
    }cout << endl;

    return 0;
}