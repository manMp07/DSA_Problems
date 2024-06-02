#include<bits/stdc++.h>
using namespace std;

// Weekly Conest 399
// DATE : 26 May 2024

//Que.- Given a string word, compress it using the following algorithm:
//      Begin with an empty string comp. While word is not empty, use the following
//      operation:
//      Remove a maximum length prefix of word made of a single character c repeating at
//      most 9 times.
//      Append the length of the prefix followed by c to comp.
//      Return the string comp.

// Time : O(|word|)
// Space : O(1)

// For eg. "aaaaaaaaaaaaabbbbb" ---> ans = "9a4a5b"

string compressedString(string word) {
    int n = word.length();
    string compressed = "";
        
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && j-i < 9 && word[i] == word[j])
            j++;
            
        compressed += char('0' + j - i);
        compressed += word[i];
        i = j-1;
    }
        
    return compressed;
}