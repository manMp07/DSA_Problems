#include<bits/stdc++.h>
using namespace std;

/***Que.
You are given a string ‘S’ of length ‘N’ where each element is numbered from ‘0’ to ‘N - 1’. You will be given a ‘Queries’ array of length ‘Q’, where each query will be of type ‘(L, R)’.

You have to check whether a substring from ‘L’ to ‘R’ contains all the distinct characters present in the given string.
For each query, you have to tell whether a substring from ‘L’ to ‘R’ contains all the distinct characters present in the given string.

Return an array of ‘0’s’ and ‘1’s, where ‘1’ shows that the substring from ‘L’ to ‘R’ contains all the distinct characters present in the string and ‘0’ shows it doesn’t contain all the distinct characters present in the given string.
*/

//Time : O(N)
//Space : O(N)

vector <int> containerQueries (int n, string &s, int q, vector <vector<int>> &queries) {
    vector<int> minPossible(n);

    vector<bool> present(26, false); // store wich characters are present
    vector<int> prevOcc(26, -1); // last occurence of every character

    for(int i = 0; i < n; i++)
        present[s[i] - 'a'] = true;

    for(int i = 0; i < n; i++){
        prevOcc[s[i] - 'a'] = i; // update last occ of current character to i.
        int start = i;
        
        // now find {maximum index = start} after that all character are present in between start to i.
        // for that we have to find minimum of all prevOcc which are present.
        for(int j = 0; j < 26; j++)
            if(present[j])
                start = min(start, prevOcc[j]);

        minPossible[i] = start;
    }

    // for eg. str = "yukppuyk"
    // minPossible = [-1, -1, -1, 0, 0, 0, 2, 4]
    // here for any i, all distinct characters are present in string str from minPossible[i] to i.

    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int l = queries[i][0];
        int r = queries[i][1];

        if(l <= minPossible[r])
            ans[i] = 1;
        else
            ans[i] = 0;
    }

    return ans;
}