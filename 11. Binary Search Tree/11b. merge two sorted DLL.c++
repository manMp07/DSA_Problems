#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//Que.- Given two Sorted Doubly Liked List, your task is merge this two list in
//      in-place sorted order.

Node* mergeSortedDLL(Node* h1, Node* h2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(h1 != NULL && h2 != NULL) {
        if(h1 -> data < h2 -> data){
            if(head == NULL)
                head = h1;
            else {
                tail -> right = h1;
                h1 -> left = tail;
            }
            tail = h1;
            h1 = h1 -> right;
        }
        else {
            if(head == NULL)
                head = h2;
            else {
                tail -> right = h2;
                h2 -> left = tail;
            }
            tail = h2;
            h2 = h2 -> right;
        }
    }

    while(h1 != NULL) {
        tail -> right = h1;
        h1 -> left = tail;
        tail = h1;
        h1 = h1 -> right;
    }

    while(h1 != NULL) {
        tail -> right = h2;
        h2 -> left = tail;
        tail = h2;
        h2 = h2 -> right;
    }
    
    return head;
}