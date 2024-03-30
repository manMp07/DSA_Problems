#include<bits/stdc++.h>
using namespace std;

//Que.- For given a string 'STR'. Your task is to find all non-empty possible subsequence
//      of 'STR'.

/***Recursive Solution***/
//Time : O(2^N)
//Space : O(N^2)

/***Using Bit Manipulation***/
//Time : O(N * 2^N)
//Space : O(N^2)

vector<string> subsequences(string str){
	int n = str.size();
    int subsets = 1 << n;
    vector<string> ans;

    // i is starting from 1, bcoz we don't need null subset
    for(int i = 1; i < subsets; i++){
        string temp = "";
        for(int j = 0; j < n; j++){
            if(i & (1 << j))
                temp = temp + str[j];
        }
        ans.push_back(temp);
    }

    return ans;
}