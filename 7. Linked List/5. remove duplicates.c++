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

//Que.- Given a sorted singly linked list consisting of N nodes. The task is to remove duplicates
//      (nodes with duplicate values) from the given list (if exists).

Node* removeDuplicates(Node *head){
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    Node* curr = head;
    
    while(curr -> next != NULL) {
        if(curr -> data != curr -> next -> data) {
            curr = curr -> next;
        }
        else{
            Node* temp = curr -> next -> next;
            curr -> next -> next = NULL;
            delete curr->next;
            curr-> next = temp;
        }
    }
    
    return head;
}