#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a number 'N' in the form of a string 'S', your task is to find the
//      smallest number strictly greater than the given number 'N' which is a palindrome.

//Time : O(N)
//Space : O(N)

void increaseByOne(string &s, int n){
	int carry = 1;
    
    for (int i = s.length() - 1; i >= 0; --i) {
        int sum = (s[i] - '0') + carry;
        s[i] = (sum % 10) + '0';
        carry = sum / 10;

        if (carry == 0)
        	break;
    }

    if (carry > 0)
        s = to_string(carry) + s;
}

string oddLengthPalindrome(string s, int n){
	// Find middle element
	int mid = n/2;
	char midChar = s[mid];
	string left = s.substr(0, n/2);
	string right = s.substr(mid+1, n/2);

	// make reveredLeft
	string reversedLeft = left;
	reverse(reversedLeft.begin(), reversedLeft.end());

	string ans;
	
	if(reversedLeft < right){
		// Increased mid by 1 & copy mirror of left on right
		left = left + midChar;
		increaseByOne(left, n/2+1);

		string newLeftReversed = left.substr(0,n/2);
		reverse(newLeftReversed.begin(), newLeftReversed.end());
		ans.append(left);
		ans.append(newLeftReversed);
	}
	else{
		// Copy mirror of left on right
		ans.append(left);
		ans.push_back(midChar);
		ans.append(reversedLeft);
	}
	
	return ans;
}

string evenLengthPalindrome(string s, int n){
	int mid = n/2;
	string left = s.substr(0, n/2);
	string right = s.substr(mid, n/2);

	string reversedLeft = left;
	reverse(reversedLeft.begin(), reversedLeft.end());

	string ans;
	if(reversedLeft < right){
		// Increased left by 1 & copy mirror of left on right
		increaseByOne(left, n/2);

		string newLeftReversed = left;
		reverse(newLeftReversed.begin(), newLeftReversed.end());
		ans.append(left);
		ans.append(newLeftReversed);
	}
	else{
		// Copy mirror of left on right
		ans.append(left);
		ans.append(reversedLeft);
	}
	
	return ans;
}

bool isPalindrome(string &s, int n){
	for(int i = 0; i < n/2; i++){
		if(s[i] != s[n-1-i])
			return false;
	}
	return true;
}

string nextLargestPalindrome(string s, int length){
	if(isPalindrome(s, length)){
		increaseByOne(s, length);
		length = s.length();
	}

	// For odd length strings
	if(length%2 == 1)
		return oddLengthPalindrome(s, length);
	else
		return evenLengthPalindrome(s, length);
}