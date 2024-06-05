#include<bits/stdc++.h>
using namespace std;

// Weekly Conest 400
// DATE : 02 June 2024

//Que.- You are given a positive integer days representing the total number of days an
//      employee is available for work (starting from day 1). You are also given a 2D array
//      meetings of size n where, meetings[i] = [start_i, end_i] represents the starting
//      and ending days of meeting i (inclusive).
//      Return the count of days when the employee is available for work but no meetings
//      are scheduled.
//      Note: The meetings may overlap.

// Time : O(N*logN)
// Space : O(1)

// [1,3][2,5][6,7][9,10]; D = 12

int countDays(int days, vector<vector<int>>& meetings){
    sort(meetings.begin(), meetings.end()); // sort start-time wise

    int lastMeet = 0;
    int nonMeet = 0;

    for(int i = 0; i < meetings.size(); i++){
        int start = meetings[i][0];
        int end = meetings[i][1];

        if(start > lastMeet)
            nonMeet += start - lastMeet - 1;

        lastMeet = max(end, lastMeet);
    }

    // if any days are remains after last meeting
    nonMeet += days - lastMeet;

    return nonMeet;
}