#include<bits/stdc++.h>
using namespace std;

// DATE : 18 June 2024

//Que.- Given a circular sheet of radius, r. Find the total number of rectangles with
//      integral length and width that can be cut from the sheet that can fit on the
//      circle, one at a time.

int rectanglesInCircle(int r) {
    /* Pythagoras Theorem : x^2 + y^2 = (2*r)^2 */
    
    /*
        x^2 + y^2 = (2*r)^2 &
        x^2 + y^2 < (2*r)^2 are possible
        but
        x^2 + y^2 > (2*r)^2 is not possible.
    */
    
    int ans = 0;
    for(int x = 1; x <= 2*r; x++){
        for(int y = 1; y <= 2*r; y++){
            if(x*x + y*y <= 4*r*r)
                ans++;
        }
    }
    return ans;
}