#include<bits/stdc++.h>
using namespace std;

//Que.- You are given a linked list of N nodes and an integer 'K', where K is less than
//      or equal to N.
//      Your task is to reverse the order of each group of K consecutive nodes.
//      If N is not divisible by K, then the last group of nodes should remain unchanged

class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this->data;
        // memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

int getLength(Node* head) {
    int len = 0;
    while(head != NULL) {
        head = head -> next;
        len++;
    }

    return len;
}

Node* kReverse(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }

    //step-1 : reverse first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    //step-2 : recursion dekhlega aage ka
    if(forward != NULL && getLength(forward) >= k) {
        head -> next = kReverse(forward, k);
    }
    else if(getLength(forward) < k){ // N is not divisible by K
        head -> next = forward;
    }

    //step-3 : return head of reversed list
    return prev;

    // Time : O(N)
    // Space : O(N)
}