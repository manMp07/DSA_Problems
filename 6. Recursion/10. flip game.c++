#include<bits/stdc++.h>
using namespace std;

/* Que. */
// Ninja and his friend are playing a game called flip game. They are given a string ‘STR’
// containing only two characters, '$' and '*'.
// In this game, Ninja and his friend take turns to flip two consecutive "$$" to "**".
// The flip game ends when Ninja or his friend can no longer make a move, i.e., there is
// no consecutive "$" present in the 'STR' and, therefore, the other person will be the
// winner of the game.
// Both the players play the game optimally in alternate turns. Given that Ninja starts the
// game i.e. takes the first turn, your task is to find out if he wins the game.

bool canNinjaWin(string& str) {
    // Check if length of str is less than 2
    if(str.length() < 2) {
        return false;
    }

    // Iterate i from 0 to length of str - 2
    for(int i = 0; i < str.length()-1; i++) {
        if(str[i] == '$' && str[i+1] == '$') {
            string changed_str = str.substr(0,i) + "**" + str.substr(i+2);

            // Create a recursive call for changedStr
            if(canNinjaWin(changed_str) == false) {  
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    cout << canNinjaWin(s) << endl;
    return 0;
}