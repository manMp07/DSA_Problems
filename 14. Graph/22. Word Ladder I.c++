#include<bits/stdc++.h>
using namespace std;

/***Que.
Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.

In this problem statement, we need to keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList
Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.*/

//Time : O(N*M*26); M = Word Length
//Space : O(N)

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    unordered_set<string> st(wordList.begin(), wordList.end());

    q.push({beginWord, 1});
    st.erase(beginWord);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == endWord)
            return steps;

        for(int i = 0; i < word.length(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // word exist in set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

