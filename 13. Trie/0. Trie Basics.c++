#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isTerminal;
    char data;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie{

    void insertUtil(TrieNode* root, string word, int i){
        if(i == word.length()){
            root -> isTerminal = true;
            return;
        }

        int idx = word[i] - 'a';
        TrieNode* child = root -> children[idx];

        if(child == NULL){
            child = new TrieNode(word[i]);
            root -> children[idx] = child;
        }

        insertUtil(child, word, i+1);
    }

    bool searchUtil(TrieNode* root, string word, int i){
        if(i == word.length()){
            return root -> isTerminal;
        }

        int idx = word[i] - 'a';
        TrieNode* child = root -> children[idx];

        if(child == NULL)
            return false;
        
        return searchUtil(child, word, i+1);
    }

    void deleteUtil(TrieNode* root, string word, int i){
        if(i == word.length()){
            root -> isTerminal = false;
            return;
        }

        int idx = word[i] - 'a';
        TrieNode* child = root -> children[idx];

        if(child)
            deleteUtil(child, word, i+1);
    }

public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        insertUtil(root, word, 0);
    }

    bool searchWord(string word){
        return searchUtil(root, word, 0);
    }

    void deleteWord(string word){
        return deleteUtil(root, word, 0);
    }
};

int main() {
    Trie* t = new Trie;
    t -> insertWord("man");
    t -> insertWord("mango");
    t -> insertWord("coder");
    t -> insertWord("monkey");
    t -> insertWord("nest");

    t -> deleteWord("nest");
    t -> insertWord("neso");

    cout << t -> searchWord("nest") << endl;
    cout << t -> searchWord("neso") << endl;
}