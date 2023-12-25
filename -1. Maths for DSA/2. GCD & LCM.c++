#include<iostream>
#include<vector>

// Relation between LCM & GCD : lcm(a,b) * gcd(a,b) = a * b

int gcd(int a, int b) {
    if(a == 0)
        return b;
    
    if(b == 0)
        return a;

    while(a != b) {
        if(a > b) 
            a = a-b;
        else
            b = b - a;
    }

    return a;
}

int recursiveGCD(int a, int b) {
    if(a == 0)
        return b;

    if(b == 0)
        return a;

    return recursiveGCD(b, a%b);
}