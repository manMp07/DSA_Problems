#include<bits/stdc++.h>
using namespace std;

//Que.- Implement Stack to store integer data using two Queues.

// using two Queues
class Stack {
	queue<int> q1;
    queue<int> q2;
    int size;

    public:
    Stack() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(q1.empty())
            return true;
        else
            return false;
    }

    void push(int element) {

        while(!q1.empty()) {
            int num = q1.front();
            q1.pop();
            q2.push(num);
        }

        q1.push(element);
        size++;

        while(!q2.empty()) {
            int num = q2.front();
            q2.pop();
            q1.push(num);
        }
    }

    int pop() {
        if(q1.empty()) {
            return -1;
        }

        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if(q1.empty()) {
            return -1;
        }

        return q1.front();
    }
};

// using one Queue only
class Stack {
    public:
    queue<int> *q1;

    // Constructor.
    Stack() {  
        q1 = new queue<int>();
    }

    int getSize() {
        return q1 -> size();  
    }

    bool isEmpty() {
        return (getSize() == 0);
    }

    void push(int data) {
        // Get the size of the queue.
        int size = q1 -> size();  

        // Enqueue the new data to the queue.
        q1 -> push(data);         

        // Make the new data front of the queue.
        for (int i = 0; i < size; i++) {
            q1 -> push(q1 -> front());
            q1 -> pop();
        }
    }

    int pop() {
        // If empty, return -1.
        if (isEmpty()) {  
            return -1;
        }

        // Simply dequeue from the queue q1.
        int ans = q1 -> front();  
        q1 -> pop();
        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        int ans = q1 -> front();

        return ans;
    }
};