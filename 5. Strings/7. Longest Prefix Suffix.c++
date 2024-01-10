#include<bits/stdc++.h>
using namespace std;

/*Finding LPS is also used in KMP algrithm.*/

//Que.- You are given a string ‘str’. Find the longest prefix in the string which is
//      also a suffix of the string, excluding the string itself.
//      If there's no such string return an empty string "".

/*One of The HARDEST algorithms in the whole DSA*/
//Time : O(N)
//Space : O(N)

string longestPrefixSuffix(string &str){
    int n = str.length();
    int pre = 0, suff = 1;
    vector<int> lps(n);

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
            
            else{
                pre = lps[pre-1];
            }
        }
    }

    return str.substr(0, lps[n-1]);
}