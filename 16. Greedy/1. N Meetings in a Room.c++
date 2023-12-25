#include<bits/stdc++.h>
using namespace std;

//Que.- There is one meeting room in a firm. There are N meetings in the form of
//      (start[i], end[i]) where start[i] is start time of meeting i and end[i] is
//      finish time of meeting i.
//      What is the maximum number of meetings that can be accommodated in the
//      meeting room when only one meeting can be held in the meeting room at a
//      particular time?
//      Note: Start time of one chosen meeting can't be equal to the end time of
//      the other chosen meeting.

//Time : O(N*logN)
//Space : O(N)

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end){
    vector<pair<int,int>> meetings;

    for(int i = 0; i < start.size(); i++){
        pair<int, int> currPair = make_pair(start[i], end[i]);
        meetings.push_back(currPair);
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int count = 1;
    int ansEnd = meetings[0].second;

    for(int i = 1; i < meetings.size(); i++) {
        if(meetings[i].first > ansEnd){
            count++;
            ansEnd = meetings[i].second;
        }
    }

    return count;
}