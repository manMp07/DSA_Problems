#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two strings 'Str' and 'Pattern' consisting of lowercase English
//      alphabets. Your task is to find whether the 'Pattern' is present in 'Str' as
//      a substring or not.

/***Brute Force***/
//Time : O(N*M)
//Space : O(1)

bool findPattern(string pattern, string str){
    int n = str.size();
    int m = pattern.size();

    if(m > n)
        return false;

    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < m && pattern[j] == str[i+j])
            j++;
        
        if(j == m)
            return true;
    }

    return false;
}

/***Using Longest Prefix Suffix***/
//Time : O(N+M)
//Space : O(M)

void getLPS(string str, vector<int> &lps) {
    int n = str.length();
    int pre = 0, suff = 1;

    while(suff < n) {
        // match
        if(str[pre] == str[suff]) {
            lps[suff] = pre+1; //prefix length store krwai
            pre++;
            suff++;
        }

        //no match -> prefix ko pichhe jump krana pdega
        else{
            if(pre == 0){ //pichhe nahi ja skta
                lps[suff] = 0;
                suff++;
            }
            
            else
                pre = lps[pre-1];
        }
    }
}

bool findPattern(string pattern, string str){
    int n = str.size();
    int m = pattern.size();
    vector<int> lps(m);

    getLPS(pattern, lps);

    int first = 0; //iterate over str
    int second = 0; //iterate over pattern

    while(first < n) {
        if(str[first] == pattern[second]){
            first++;
            second++;

            if(second == m)
                return true;
        }
        else {
            if(second != 0)
                second = lps[second-1];
            else
                first++;
        }
    }

    return false;
}