#include <bits/stdc++.h>
using namespace std;

//Que.- Implement queue data structure using array & Linked List

// All functions has Time : O(1)

// Using Array
class Queue {
    public:
    int *arr;
    int size;
    int qfront;
    int rear;

    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(rear == qfront)
            return true;

        else
            return false;
    }

    void push(int data) {
        if(rear == size)
            return;

        arr[rear] = data;
        rear++;
    }

    int pop() {
        if(rear == qfront)
            return -1;

        int value = arr[qfront];
        arr[qfront] = 0;
        qfront++;

        if(qfront == rear) {//don't want to waste memory
            qfront = 0;
            rear = 0;
        }
        
        return value;
    }

    int front() {
        if(rear == qfront)
            return -1;
        
        return arr[qfront];
    }
};

// Using Linked List
class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

class Queue {
    public:
    Node* head;
    Node* tail;
    
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        if(head == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);

        //first element
        if(isEmpty()) {
            head = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;
            tail = temp;
        }
        
    }

    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        
        int ans = head -> data;
        Node* temp = head -> next;
        head -> next = NULL;
        delete head;
        
        head = temp;

        return ans;
    }

    int front() {
        if(isEmpty())
            return -1;
        else
            return head->data;
    }
};