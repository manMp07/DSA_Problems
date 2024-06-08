#include <bits/stdc++.h>
using namespace std;

//Que.- Given a string s containing only three types of characters: '(', ')' and '*',
//      return true if s is valid.
//      The following rules define a valid string:
//      Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//      Any right parenthesis ')' must have a corresponding left parenthesis '('.
//      Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//      '*' could be treated as a single right parenthesis ')' or a single left parenthesis
//     '(' or an empty string "".

// This Can be done using DP with
// Time : O(N*N)
// Space : O(N*N)

/*** Greedy Approach using Range ***/
// Time : O(N)
// Space : O(1)

bool checkValidString(string &s){
	int mini = 0;
	int maxi = 0;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == '('){
			mini++;
			maxi++;
		}
		else if(s[i] == ')'){
			mini--;
			maxi--;
		}
		else{
			mini--;
			maxi++;
		}

		if(mini < 0) mini = 0;
		if(maxi < 0) return false;
	}

	return (mini == 0);
}