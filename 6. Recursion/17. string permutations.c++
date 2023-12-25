#include<bits/stdc++.h>
using namespace std;

// Que.- You are given an input string S. Your task is to find and return all possible
//       permutations of the input string.

//**marked for revision
void solve(string str, int index, vector<string>& ans) {
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, index+1, ans);
        swap(str[index], str[j]);
    }
}

vector<string> findPermutations(string &str) {
    vector<string> ans;
    if(str.length() < 2) {
        ans.push_back(str);
        return ans;
    }

    int index = 0;
    solve(str, index, ans);

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<string> ans = findPermutations(s);

    for(auto x : ans) {
        cout << x << " ";
    }cout << endl;

    return 0;
}