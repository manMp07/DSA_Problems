#include<bits/stdc++.h>
using namespace std;

//Que.- Write a function to find the longest common prefix string amongst an array
//      of strings. If there is no common prefix, return an empty string "".

// This can be also done by using sorting.

// Time : O(N*M)
// Space : O(N*M)

class TrieNode {
    public :
    
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //first character is present
        if(root -> children[index])
            child = root -> children[index];
        else{
            child = new TrieNode(word[0]);
            root -> childCount++;
            root -> children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void prefixFind(string str, string &ans){
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if(root -> childCount == 1){
                ans.push_back(ch);
                root = root -> children[ch - 'a'];
            }
            else
                break;

            if(root -> isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie* t = new Trie('\0');
    
    for(int i = 0; i < arr.size(); i++) {
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> prefixFind(first, ans);

    return ans;
}