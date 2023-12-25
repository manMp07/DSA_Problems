#include<iostream>
using namespace std;

// Que.- Given a singly Linked List of integers. your task is to return the head of
//       reversed linked list.

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

Node* approach1(Node* head) {
    if(head == NULL || head-> next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void solve(Node* &head, Node* curr, Node* prev) {
    if(curr == NULL) {
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    curr -> next = prev;
    solve(head, forward, curr);
}

Node* approach2(Node *head) {
    Node* prev = NULL;
    Node* curr = head;

    solve(head, curr, prev);
    return head;
}

Node* reverse(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* smallHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;
    return smallHead;
}

Node* approach3(Node *head) {
    return reverse(head);
}
