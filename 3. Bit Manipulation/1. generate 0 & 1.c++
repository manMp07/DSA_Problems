#include<iostream>
using namespace std;

//Que.- Given a function rand50() that returns 0 or 1 with equal probability, write
//      a function that returns 1 with 75% probability and 0 with 25% probability
//      using rand50() only. Minimize the number of calls to the rand50() method.

int rand50() {
    return (rand() & 1);
}

/*int rand75() {
    return (rand50() | rand50());
}*/

/*int rand75() {
    return !(rand50() & rand50());
}*/

int rand75() {
    int x = rand50(); //x is one of {0,1}

    x = x << 1; //x is now one of {00, 10}

    x = x ^ rand50(); //x is now oe of {00, 01, 10, 11}

    return (x > 0) ? 1 : 0;
}

int main() {
    for(int i = 0; i < 20; i++) {
        cout << rand50();
    }
    cout << endl;

    for(int i = 0; i < 20; i++) {
        cout << rand75();
    }
}