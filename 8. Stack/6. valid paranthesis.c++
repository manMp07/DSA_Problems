#include<bits/stdc++.h>
using namespace std;

// Given string 'S', containing '(',')','{','}','[' and ']'. Return true if string is
// balanced, else return false.

// {{()[{[]}([])]}}

bool isValidParenthesis(string s){
    if(s.size() % 2 == 1) {
        return false;
    } 

    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        //if opening bracket, stack push
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        //if closing bracket, stacktop check & pop
        else {
            if(!st.empty()) {
                char top = st.top();
                if( (ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[') )
                {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else { // s[i] is closing bracket & stack is empty
                return false;
            }
        }
    }

    if(st.empty()) {
        return true;
    }
    else {
        return false;
    }
}