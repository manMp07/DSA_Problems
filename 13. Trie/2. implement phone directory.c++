#include<bits/stdc++.h>
using namespace std;

//Que.- Given a list of contacts that exist in a phone directory. The task is to
//      implement a search query for the phone directory. The search query on a
//      string ‘str’ displays all the contacts which prefixes as ‘str’. One special
//      property of the search function is that when a user searches for a contact
//      from the contact list then suggestions (Contacts with prefix as the string
//      entered so for) are shown after user enters each character.

// Time : O(N*M*M)
// Space : O(N*M)

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index]){
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }


    void printSuggestion(TrieNode* root, vector<string> &temp, string prefix) {
        if(root -> isTerminal)
            temp.push_back(prefix);

        for(int i = 0; i < 26; i++) {
            if(root -> children[i]){
                prefix.push_back(root -> children[i] -> data);
                printSuggestion(root -> children[i], temp, prefix);

                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str) {
        TrieNode* prev = root;
        vector<vector<string>> ans;

        string prefix = "";
        for(int i = 0; i < str.length(); i++) {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            TrieNode* curr = prev -> children[lastCh - 'a'];

            if(curr == NULL)
                break;
        
            vector<string> temp;
            printSuggestion(curr, temp, prefix);
            ans.push_back(temp);
            temp.clear();

            prev = curr;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr){
    
    // create a Trie of given strings
    Trie* t = new Trie;
    for(int i = 0; i < contactList.size(); i++) {
        t -> insertWord(contactList[i]);
    }

    return t -> getSuggestion(queryStr);
}