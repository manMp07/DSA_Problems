#include<bits/stdc++.h>
using namespace std;

//Que.- Given string only contains '(', ')', '+', '-', '*', '/' and lowercase english letters
//      Your task is to return true if given string contains redundant bracket else return
//      false.

// Note : A pair is said to be redundant when a subexpression is surrounded by needless
//        brackets.

bool findRedundantBrackets(string &str){
    stack<char> st;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }

        else if(ch == ')') {
            bool isRedundandt = true;

            while(st.top() != '(') {
                char top = st.top();

                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isRedundandt = false;
                }
                st.pop();
            }

            if(isRedundandt == true) {
                return true;
            }
            st.pop();
        }
    }

    return false;
}