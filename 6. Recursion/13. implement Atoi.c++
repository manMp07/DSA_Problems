#include<iostream>
#include<string>
using namespace std;

// Que.- Given a string 'str' of length 'n', convert the string to an integer. If there are
//       no number in the string return 0.
//       ex. -app339er ---> -339

int atoi(int i, int ans, string& str) {
    if(i == str.size())
        return ans;

    if('0' <= str[i] && str[i] <= '9')
        return atoi(i+1, ans*10 + str[i] - '0', str);
    else
        return atoi(i+1, ans, str);
}

int atoi(string str) {
    int num = atoi(0, 0, str);

    if(str[0] == '-')
        num *= -1;
    return num;
}

int main() {
    string s; cin >> s;
    
    cout << atoi(s) << endl;

    return 0;
}