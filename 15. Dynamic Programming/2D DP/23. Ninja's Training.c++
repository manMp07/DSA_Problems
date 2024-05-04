#include<bits/stdc++.h>
using namespace std;

//Que.- A Ninja has an ‘N’ Day training schedule. He has to perform one of these three
//      activities (Running, Fighting Practice, or Learning New Moves) each day. There are
//      merit points associated with performing an activity each day. The same activity can’t
//      be performed on two consecutive days. We need to find the maximum merit points the
//      ninja can attain in N Days.

/***Recursion***/
// Time : O(Exponential)
// Space : O(N)

int solve(vector<vector<int>> &points, int n, int day, int lastAct){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != lastAct)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    int maxAns = -1;
    for(int task = 0; task < 3; task++){
        if(task != lastAct){
            int activity = points[day][task] + solve(points, n, day-1, task);
            maxAns = max(maxAns, activity);
        }
    }

    return maxAns;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    return solve(points, n, n-1, 3);
}

/***Bottom Up Approach(Tabulation)***/
// Time : O(N*3*3)
// Space : O(N*3)

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(3));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] =  max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);

    for(int day = 1; day < n; day++){
        for(int last = 0; last <= 2; last++){
            dp[day][last] = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last){
                    int activity = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

/***Space Optimization***/
// Time : O(N*3*3)
// Space : O(3)

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> prev(3);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] =  max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);

    for(int day = 1; day < n; day++){
        vector<int> temp(3);
        for(int last = 0; last <= 2; last++){
            temp[last] = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last){
                    int activity = points[day][task] + prev[task];
                    temp[last] = max(temp[last], activity);
                }
            }
        }
        prev = temp;
    }

    return max(prev[0], max(prev[1], prev[2]));
}