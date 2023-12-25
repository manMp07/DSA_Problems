#include<bits/stdc++.h>
using namespace std;

//Que.- Given an input stream STR of n characters consisting only of lower case alphabets.
//      While reading characters from the stream, you have to tell which character has
//      appeared only once in the stream upto that point. If there are many characters
//      that have appeared only once, you have to tell which one of them was the first
//      one to appear. If there is no such character then append '#' to the answer.

// Time : O(N)
// Space : O(N)

string FirstNonRepeating(string str){
	string ans;
	map<char, int> count;
	queue<char> q;
		    
	for(int i = 0; i < str.size(); i++) {
	    char ch = str[i];

		//increase count
		count[ch]++;
		        
		//push in Queue
		q.push(ch);
		        
		//repeating character
		while(!q.empty() && count[q.front()] > 1) {
		    q.pop();
		}

		if(q.empty())
		    ans.push_back('#');

		else //non repeating character
		    ans.push_back(q.front());
	}
		    
	return ans;
}