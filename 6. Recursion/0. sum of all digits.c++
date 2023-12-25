#include<iostream>
using namespace std;

int sum(int n) {
    if(n >= 0 && n <= 9) {
        return n;
    }

    int ans = (n%10) + sum(n/10);
    return ans;
}

int main() {
    int n = 12345;
    cout << sum(n);

    return 0;
}