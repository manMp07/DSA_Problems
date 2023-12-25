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
        // memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

//Que.- Given Singly Linked List of 'N' nodes of integer data and an integer 'K'. Your task
//      is to remove the K'th node from the end of the given linked list.

// Time : O(N)
// Space : O(N)

Node* removeKthNode(Node* head, int K){
    int size = 0;
    Node* temp = head;

    // Find size of a Linked list
    while(temp != NULL) {
        size++;
        temp = temp -> next;
    }

    int position = size - K + 1;

    Node* curr = head;
    Node* prev = NULL;

    if(position == 1) {
        head = curr -> next;
        curr -> next = NULL;
        delete curr;
        return head;
    }

    for(int i = 1; i < position; i++) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;

    return head;
}

Node* removeKthNode2(Node* head, int K){
    if(head == NULL || K == 0) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    for(int i = 0; i < K; i++) {

        //If head is the Kth node from end of linked list
        if(fast -> next == NULL) {
            Node* next = head -> next;
            head -> next = NULL;

            delete head;
            head = next;

            return head;
        }
        fast = fast -> next;
    }

    while(fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = slow -> next -> next;

    return head;
}