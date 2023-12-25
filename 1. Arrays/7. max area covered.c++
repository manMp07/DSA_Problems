#include<bits/stdc++.h>
using namespace std;

//For given array, each element suggest height of line drawn from 'i'th position. Find two lines, which together with x-axis forms a container, such that it cover the most area and return that maximum Area.

int maxArea(vector<int> height) {
    int maxArea = 0;
    int hi = height.size() - 1;
    int lo = 0;
    while(lo < hi) {
        int currentArea = (hi-lo) * min(height[lo], height[hi]);
        if(maxArea < currentArea) {
            maxArea = currentArea;
        }

        if(height[lo] <= height[hi]) {
            lo++;
        }
        else if(height[lo] > height[hi]) {
            hi--;
        }
    }
    return maxArea;
}

int main() {
    vector<int> container;
    int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        int element;
        cin >> element;
        container.push_back(element);
    }

    cout << maxArea(container) << endl;

    return 0;
}