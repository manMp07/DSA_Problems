#include <bits/stdc++.h>
using namespace std;

//Que.- Implement 'N' Queues using an array of size 'S'

// Time : O(1)
// Space : O(N+S)

class NQueue{
    int n;
    int s;
    int *arr;
    int *front;
    int *rear;
    int *next;

    int freespot;
    public:
    // Initialize your data structure.
    NQueue(int n, int s){
        this -> s = s;
        this -> n = n;
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        freespot = 0;
        
        for(int i = 0; i < n; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < s; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
        
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot == -1) {
            return false;
        }

        int index = freespot;

        freespot = next[index];
        
        if(front[m-1] == -1) { //first element
            front[m-1] = index;
        }
        else {
            next[rear[m-1]] = index;
        }

        next[index] = -1;

        rear[m-1] = index;

        arr[index] = x;

        return true;
    }

    // Dequeues topelement from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1] == -1) {
            return -1;
        }
        
        int index = front[m-1];
        
        front[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};