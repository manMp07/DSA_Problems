#include<bits/stdc++.h>
using namespace std;

//Que.- Reverse the given string word-wise where all words are spareted by space. Individual
//      words should remain as it is.

// Time Complexity : O(n)
// Space Complexity : O(n)
string reverseStringWordWise(string str){
    vector <string> dummy_ans;
    string s = "";

    // filling dummy_ans where each element is a word.
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            dummy_ans.push_back(s);
            s = "";
        }
        else {
            s = s + str[i];
        }
    }

    // last word remaining
    dummy_ans.push_back(s);

    string ans = "";

    // traverse the dummy_ans from last & insserting each element in answer.
    for(int i = dummy_ans.size() - 1; i >= 0; i--) {
        if(i != 0 ){
            ans += dummy_ans[i];
            ans += " ";
        }
        else { // last word dosen't required space
            ans += dummy_ans[i];
        }
    }

    return ans; 
}

int main() {
    string s;
    getline(cin, s);
    string answer = reverseStringWordWise(s);
    cout << answer << endl;

    return 0;
}