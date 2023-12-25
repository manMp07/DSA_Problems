#include<bits/stdc++.h>
using namespace std;

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

//Que.- Given an unsorted linked list of N nodes. The task is to remove duplicate
//      elementss from this unsorted Linked List.

Node *removeDuplicates(Node *head){

    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        if(visited[curr -> data] == true) {
            prev -> next = curr -> next;
            delete(curr);
            curr = prev -> next;
        }
        else {
          visited[curr->data] = true;
          
          prev = curr;
          curr = curr->next;
        }
    }
    return head;
}