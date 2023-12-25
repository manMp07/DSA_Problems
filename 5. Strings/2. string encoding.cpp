#include <bits/stdc++.h>
using namespace std;

// For given a string message, you need to return encoded message.

string encode(string &message){
    int n = message.size();
    string encoded_Message = "";

    for (int i = 0; i < n; i++) {
        char currentChar = message[i];
        int charFreq = 1;
        while (i + 1 < n && message[i + 1] == currentChar) {
            i++;
            charFreq++;
        }

        encoded_Message.push_back(currentChar);
        encoded_Message.append(to_string(charFreq));
    }
    return encoded_Message;
}

int main() {
    string s;
    getline(cin, s);
    string answer = encode(s);
    cout << answer << endl;

    return 0;
}