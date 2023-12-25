#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* insertionSortLL(Node *head){
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* dummy = new Node(-1);
    dummy -> next = head;

    Node* curr = head -> next;
    Node* prev = head;

    while(curr != NULL) {
        //already sorted
        if(prev -> data <= curr -> data) {
            prev = curr;
            curr = curr -> next;
            continue;
        }

        Node* temp = dummy;

        // set 'temp' to the previons position of node to be inserted
        while( (temp->next->data) < (curr->data) ) {
            temp = temp -> next;
        }
        prev -> next = curr -> next;
        curr -> next = temp -> next;
        temp -> next = curr;
        curr = prev -> next;
    }

    return dummy -> next;
}