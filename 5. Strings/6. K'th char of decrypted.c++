#include<bits/stdc++.h>
using namespace std;

//You have been given encrypted string, you need to find k'th character of decrypted string.

char kThCharaterOfDecryptedString1(string s, long long k){
    // Time : O(M)
    // Space : O(M) ; M = length of decrypted string
    long long i, j;
    long long n = s.length();
    string substring;
    long long freqOfSubstring;
    string decryptedString = "";

    i = 0;

    while (i < n){
        j = i;
        substring = "";
        freqOfSubstring = 0;

        //  Find the substring by traversing the string until no digit is found.
        while (j < n && islower(s[j])){
            substring.push_back(s[j]);
            j++;
        }

        //  Find the frequency of preceding substring.
        while (j < n && isdigit(s[j])){
            freqOfSubstring = freqOfSubstring * 10 + (s[j] - '0');
            j++;
        }

        i = j;

        // Append the subtring freqOfSubstring times
        while (freqOfSubstring--){
            decryptedString.append(substring);
        }
    }

    //  Return 'k'Th character of Decrypted String
    return decryptedString[k-1];
}

char kThCharaterOfDecryptedString2(string s, long long k){
    // Time : O(N)
    // Space : O(1) ; N = length of encrypted string
    
    long long i, j;
    long long n = s.length();
    long long substringLength;
    long long resultantLength;
    long long freqOfSubstring;
    char kThChar;

    i = 0;

    while(i < n) {
        j = i;
        substringLength = 0;
        freqOfSubstring = 0;
        
        while(j < n && islower(s[j])){
            substringLength++;
            j++;
        }

        while(j < n && isdigit(s[j])) {
            freqOfSubstring = freqOfSubstring * 10 + (s[j] - '0');
            j++;
        }

        resultantLength = freqOfSubstring * substringLength;

        if(k > resultantLength) {
            k = k - resultantLength;
            i = j;
        }
        else {
            k = k-1;
            k = k % substringLength;
            kThChar = s[i+k];
            break;
        }
    }

    return kThChar;
}

int main() {
    string encrypted;
    int k;

    cin >> encrypted;
    cin >> k;

    cout << kThCharaterOfDecryptedString2(encrypted, k) << endl;

    return 0;
}