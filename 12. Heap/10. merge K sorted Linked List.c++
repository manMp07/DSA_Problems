#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        this -> data = 0;
        next = NULL;
    }
    Node(int data){
        this -> data = data; 
        this -> next = NULL;
    }
    Node(int data, Node* next){
        this -> data = data;
        this -> next = next;
    }
};

//Que.- Given K sorted linked lists of different sizes. The task is to merge them
//      in such a way that after merging they will be a single sorted linked list.

// Time : O(NlogK)
// Space : O(K) ; N = Total number of Nodes

class compare{
    public:
    bool operator()(Node* first, Node* second){
        return first->data > second->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    //step1
    int k = listArray.size();
    for(int i = 0; i < k; i++) {
        minHeap.push(listArray[i]);
    }

    //step2
    Node* head = NULL;
    Node* tail = NULL;
    while(!minHeap.empty()) {
        Node* top = minHeap.top();
        minHeap.pop();
        if(head == NULL){ // if answer LL is empty
            head = top;
            tail = top;
        }
        else{
            tail -> next = top;
            tail = top;
        }

        if(tail -> next != NULL) {
            minHeap.push(tail -> next);
        }
    }

    return head;
}