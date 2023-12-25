#include<bits/stdc++.h>
using namespace std;

//Que.- A celebrity is a person who is known to all but does not know anyone at a party.
//      If you go to a party of N people, find if there is a celebrity in the party or
//      not.
//      A square NxN matrix M[][] is used to represent people at the party such that if
//      an element of row i and column j  is set to 1 it means ith person knows jth
//      person. Here M[i][i] will always be 0.

int celebrity(vector<vector<int>> arr, int n) {
    stack<int> s;
    for(int i = 0; i < n; i++) {
        s.push(i);
    }
        
    while(s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
    
        if(arr[a][b])
            s.push(b);
        else
            s.push(a);     
    }
        
    int celebrity = s.top();
        
    for(int j = 0; j < n; j++) {
        if(arr[celebrity][j] == 1)
            return -1;
    }
        
    for(int i = 0; i < n; i++) {
        if(i != celebrity && arr[i][celebrity] == 0)
            return -1;
    }
        
    return celebrity;
}

int celebrity2(vector<vector<int>> arr, int n) {
    //initializing two pointers for two corners.
    int a = 0;
    int b = n - 1;
        
    //we keep moving till the a<b. 
    while (a < b) {
        if (arr[a][b])
            a++;
        else
            b--;
    }
        
    //checking if a is actually a celebrity or not.
    for (int i = 0; i < n; i++){
        //if any person doesn't know a or a knows any person, we return -1. 
        if ( (i != a) && (arr[a][i] || !arr[i][a]) )
            return -1;
    }

    //if we reach here a is celebrity so we retun a.
    return a;
}