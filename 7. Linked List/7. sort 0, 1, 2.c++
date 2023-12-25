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

//Que.- Given a liked list of 'N' nodes, where each node has an integer value that can be
//      0s, 1s or 2s. You need to sort linked list in non-decreasing oreder and the return
//      the head of the sorted list.

Node* sortList1(Node* head) {
    int zero = 0;
    int one = 0;
    int two = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == 0) {
            zero++;
        }
        else if(temp -> data == 1) {
            one++;
        }
        else if(temp -> data == 2) {
            two++;
        }
        temp = temp -> next;
    }
    temp = head;

    while(zero--) {
        temp -> data = 0;
        temp = temp -> next;
    }
    while(one--) {
        temp -> data = 1;
        temp = temp -> next;
    }
    while(two--) {
        temp -> data = 2;
        temp = temp -> next;
    }

    return head;
}

void insertAtTail(Node* &tail, Node* curr) {
    tail -> next = curr;
    tail = curr;
}

Node* sortList2(Node *head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // create separate list 0s, 1s and 2s.
    while(curr != NULL) {
        int value = curr -> data;

        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    // merge 3 sublist

    // non-empty 1s list
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    else {
        // empty 1s list
        zeroTail -> next = twoHead -> next;
    }
    
    twoTail -> next = NULL;

    head = zeroHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}