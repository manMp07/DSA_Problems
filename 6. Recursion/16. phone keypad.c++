#include<bits/stdc++.h>
using namespace std;

// Que.- Given a string S containing digits from 2 to 9 inclusive. Your task is to find all
//       possible letter combinations that the number could represent.

void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
	if(index >= digit.length()) {
		ans.push_back(output);
		return;
	}

	int number = digit[index] - '0';
	string value = mapping[number];
	
	for(int i = 0; i < value.length(); i++) {
		output.push_back(value[i]);
		solve(digit, output, index+1, ans, mapping);
		output.pop_back();
	}
}

vector<string> combinations(string digit){
	vector<string> ans;
	if(digit.length() == 0) {
		return ans;
	}

	int index = 0;
	string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string output = "";
	
	solve(digit, output, index, ans, mapping);

	return ans;
}

int main() {
    string digits;
    cin >> digits;

    vector<string> ans = combinations(digits);

    for(auto x : ans) {
        cout << x << " ";
    }

    return 0;
}