#include<bits/stdc++.h>
using namespace std;

// Que.- You are given a string 'str' containing lowercase english latter from a to z.
//       Your task is to find all non-empty possible subsequences of 'str'.

void solve(string str, string output, int index, vector<string>& ans) {
	if(index >= str.size()) {
		if(!output.empty())
			ans.push_back(output);
		return;
	}

	//exclusion
	solve(str, output, index+1, ans);

	// inclusion
	char element = str[index];
	output.push_back(element);
	solve(str, output, index+1, ans);
}

vector<string> subSequences(string str){
	vector<string> ans;
	string output = "";
	solve(str, output, 0, ans);
	return ans;
}

int main() {
    string str;
    cin >> str;

    vector<string> ans = subSequences(str);

    for(auto x : ans) {
        cout << x << " ";
    }cout << endl;

    return 0;
}