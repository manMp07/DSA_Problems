#include <bits/stdc++.h>
using namespace std;

//Que.- Given a string, which contain only two type of characters '(' & ')'. Your task is to
//      find the minimum number of parentheses either '(' or ')' we must add in the given
//      string and the resulted string become valid.

int minimumParentheses(string pattern) {
    int open_parentheses = 0;
    int ans = 0;
    for(int i = 0; i < pattern.size(); i++) {
        if(open_parentheses == 0 && pattern[i] == ')') {
            ans++;
        }
        else if(open_parentheses >= 0 && pattern[i] == '(') {
            open_parentheses++;
        }
        else if(open_parentheses > 0 && pattern[i] == ')') {
            open_parentheses--;
        }
    }

    ans += open_parentheses;
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    int answer = minimumParentheses(s);
    cout << answer << endl;

    return 0;
}