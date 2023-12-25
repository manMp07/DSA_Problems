#include<iostream>
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

//Que.- Given two decimal numbers represented by two linked lists of size N and M
//      respectively. The task is to return a linked list that represents the sum of these
//      two numbers.

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* temp = new Node(value);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
}   

Node* add(Node* first, Node* second) { 
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;

        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create a node and add in answer linked list 
        insertAtTail(ansHead, ansTail, digit);

        carry = sum/10;

        if(first != NULL)
            first = first -> next;

        if(second != NULL)
           second = second -> next;
    }

    return ansHead;
}

Node* addTwoLists(struct Node* first, struct Node* second){
    // step-1 : reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step-2 : add both lists
    Node* ans = add(first, second);
    
    // step-3 : reverse ans
    ans = reverse(ans);

    return ans;

    // Time : O(M + N)
    // Space : O(max{M, N})
}