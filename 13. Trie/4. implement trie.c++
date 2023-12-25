#include <bits/stdc++.h>
using namespace std;
/*
//Que.-   Implement a data structure ”TRIE” from scratch. Complete some functions.

1) Trie(): Initialize the object of this “TRIE” data structure.
2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.
3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this
   “TRIE”.
4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE”
   that have the string “PREFIX” as a prefix.
5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.*/

/*
	Time complexity : O(N * L) 
        Insert - O(N)
        CountWordsEqualTo - O(N)
        CountWordsStartingWith - O(N*L)
        Erase - O(N)
	Space complexity : O(N * L) 

	Where 'N' and 'L' represents the numbers of words 
	and the longest word in words.
*/

class TrieNode{
    public :

    char data;
    TrieNode* children[26];
    int terminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        terminal = 0;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0){
            root -> terminal++;
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

    void insert(string &word){
        insertUtil(root, word);
    }

    int countUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root -> terminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index]){
            child = root -> children[index];
            return countUtil(child, word.substr(1));
        }
        else{
            return 0;
        }
    }

    int countWordsEqualTo(string &word){
        return countUtil(root, word);
    }

    void countPrefix(TrieNode* root, int &cnt) {
        if(root -> terminal){
            cnt += root -> terminal;
        }

        for(int i = 0; i < 26; i++) {
            if(root -> children[i])
                countPrefix(root -> children[i], cnt);
        }
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;

        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            if(!curr -> children[index])
                return 0;
            else
                curr = curr -> children[index];
        }

        int cnt = 0;
        countPrefix(curr, cnt);

        return cnt;
    }

    void eraseUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root -> terminal--;
            return;
        }

        int index = word[0] - 'a';
        
        eraseUtil(root -> children[index], word.substr(1));
    }

    void erase(string &word){
        eraseUtil(root, word);
    }
};

/***Iterative & Optimized Solution***/

// Understand & write code from codestudio