#include<bits/stdc++.h>
using namespace std;

//Que.- Given two strings "pattern" and "str", return the index of the first occurrence of
//      "pattern" in "str", or -1 if "pattern" is not part of "str".

// Dry Run : Str = "onionionson"
//           Pattern = "onions" ---> Ans = 3

/***Brute Force***/
//Time : O(N*M)
//Space : O(1)

int findPattern(string pattern, string str){
    int n = str.size();
    int m = pattern.size();

    if(m > n)
        return -1;

    for(int i = 0; i < n; i++){
        int j = 0;
        while(j < m && pattern[j] == str[i+j])
            j++;
        
        if(j == m)
            return i;
    }

    return -1;
}

/***Using Longest Prefix Suffix***/
//Time : O(N+M)
//Space : O(M)

//LPS : Longest Prefix Suffix
void getLPS(string str, vector<int> &lps) { // This is taken from previous question
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

int findPattern(string pattern, string str){
    int n = str.size();
    int m = pattern.size();

    if(m > n)
        return -1;

    vector<int> lps(m);
    getLPS(pattern, lps);

    int first = 0; //iterate over str
    int second = 0; //iterate over pattern

    while(first < n && second < m) {
        if(str[first] == pattern[second]){
            first++;
            second++;
        }
        else {
            if(second != 0)
                second = lps[second-1];
            else
                first++;
        }
    }

    if(second == m)
        return first - second;

    return -1;
}