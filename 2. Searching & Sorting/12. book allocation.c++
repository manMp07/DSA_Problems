#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array 'arr' of integers, 'arr[i]' represents the number of pages in the
//      'i-th' book. There are 'm' number of students and the task is to allocate all the
//      books to the students.
//      Conditions : 1. Each student gets at least one book.
//                   2. Each book should be allocated to only one student
//                   3. Book allocation should be in a contiguous manner.
//      You have to allocate the book to 'm' students such that the maximum number of pages
//      assigned to a student is minimum.
//      If the allocation of book is not possible, return -1.

// Time : O(N*logN)
// Space : O(1)

// Painter's partition problem is as similer to this one.

bool isPossible(vector<int> arr, int m, int pages) {
    int students = 1;
    long long studentPages = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(studentPages + arr[i] <= pages)
            studentPages += arr[i];
        else {
            students++;
            studentPages = arr[i];
        }
    }
    
    if(students <= m)
        return true;
        
    return false;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n)
        return -1;
    
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxi = max(maxi, arr[i]);
    }
    
    int hi = sum;
    int lo = maxi;
    int mid;

    while(lo <= hi) {
        mid = (lo + hi)/2;
        if(isPossible(arr, m, mid))
            hi = mid - 1;

        else
            lo = mid + 1;
    }
    
    return lo;
}
