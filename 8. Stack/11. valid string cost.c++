#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a string 'STR' containing either '{' or '}'. Ninja wants to make 'STR'
//      valid by performing some operations on it.
//      He  can convert '{' into '}' and vise versa, and the cost of such operation is 1.
//      Your task is to determine the minimum cost to make 'STR' valid.

int findMinimumCost(string str) {
    if(str.length() % 2 == 1)
        return -1;

    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if(ch == '{')
            st.push(ch);

        else { //ch = '}'
            if(!st.empty() && st.top() == '{')
                st.pop();

            else
                st.push(ch);
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;
    while(!st.empty()) {
        if(st.top() == '{')
            b++;
        else
            a++;

        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}