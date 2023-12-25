#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "Babbar";

    stack <char> st;
    for(int i = 0; i < str.size(); i++) {
        st.push(str[i]);
    }

    string ans = "";

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans << endl;

    return 0;
}