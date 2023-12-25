#include<bits/stdc++.h>
using namespace std;

//Que.- Given the arrival and departure times of all trains that reach a railway
//      station, the task is to find the minimum number of platforms required for
//      the railway station so that no train waits. We are given two arrays that
//      represent the arrival and departure times of trains that stop.
//      If arrival time and departure time of two trains are same, then we need
//      different platforms.

/***Sorting Approach***/
//Time : O(N*logN)
//Space : O(1)

int calculateMinPatforms(int arrival[], int departure[], int n) {
    sort(arrival, arrival+n);
    sort(departure, departure+n);

    int plat_needed = 1, minPlatforms = 1;
    int i = 1, j = 0;

    while(i < n && j < n){
        if(arrival[i] <= departure[j]){
            plat_needed++;
            i++;
        }
        else if (arrival[i] > departure[j]){
            plat_needed--;
            j++;
        }

        minPlatforms = max(minPlatforms, plat_needed);
    }

    return minPlatforms;
}

/***CumalativeSum Approach***/
//Time : O(N + 2361) ~ O(N)
//Space : O(2361) ~ O(1)

int calculateMinPatforms(int arrival[], int departure[], int n) {
    int platforms[2361] = {0}; // Initializing with 0.

    int minPlatforms = 1;

    for (int i = 0; i < n; i++){
        platforms[arrival[i]]++; // Increment the count of platforms at the time of arrival.
        
        platforms[departure[i]+1]--; // Decrease the platform count just after the departure.
    }

    // We are running loop till 2361 because maximum time value in a day can be 23:60.
    for (int i = 1; i < 2361; i++){
        // Taking cumulative sum of platforms.
        platforms[i] = platforms[i] + platforms[i - 1];

        // Update minPlatforms.
        minPlatforms = max(minPlatforms, platforms[i]);
    }

    return minPlatforms;
}