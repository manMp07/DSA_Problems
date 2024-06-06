#include<bits/stdc++.h>
using namespace std;

// Weekly Conest 400 (Que.3)
// DATE : 02 June 2024

//Que.- You are given a string s. It may contain any number of '*' characters. Your task
//      is to remove all '*' characters.
//      While there is a '*', do the following operation:
//      Delete the leftmost '*' and the smallest non-'*' character to its left. If there
//      are several smallest characters, you can delete any of them.
//      Return the lexicographically smallest resulting string after removing all '*'
//      characters.

/***Using Vector of Vector***/
// Time : O(N) + O(NlogN)

string clearStars(string s) {
    vector<vector<int>> mp(26);

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '*'){
            for(int j = 0; j < 26; j++){
                if(!mp[j].empty()){
                    mp[j].pop_back();
                    break;
                }
            }
        }
        else{
            mp[s[i] - 'a'].push_back(i);
        }
    }

    string ans = "";

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '*') continue;

        if(!mp[ch-'a'].empty() && binary_search(mp[ch-'a'].begin(), mp[ch-'a'].end(), i))
            ans.push_back(ch);
    }

    return ans;
}

/***Using Vector of Set***/
// Time : O(NlogN) + O(NlogN)
//
/* vector<set<int, greater<int>>> mp;
   This stores values in descending order in each set
*/


/***Using Set of Pair***/
//Time : O(NlogN) + O(NlogN)
//
/* set<pair<char,int>> st;
   It stores lexicographically order. If the char components are equal, then the int
    components are compared.
*/