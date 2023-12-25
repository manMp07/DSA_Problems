#include <bits/stdc++.h>
using namespace std;

//Que.- Given a string of alphabetic characters. Return the count of distinct
//      substrings of the string using the Trie data structure.

// Time : O(N*N)

class TrieNode{
    public:
    TrieNode* children[26];

    bool cointainKey(char ch){
        return children[ch - 'a'];
    }
    void put(char ch){
        TrieNode* temp = new TrieNode();
        children[ch - 'a'] = temp;
    }

    TrieNode* get(char ch){
        return children[ch - 'a'];
    }
};

int distinctSubstring(string &word) {
    int n = word.length();
    int cnt = 0;
    TrieNode* root = new TrieNode();
    
    for(int i = 0; i < n; i++) {
        TrieNode* node = root;
        
        for(int j = i; j < n; j++) {
            // if not contain, than create
            if(!node -> cointainKey(word[j])){
                cnt++;
                node -> put(word[j]);
            }
            node = node -> get(word[j]);
        }
    }

    return cnt;
}