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

//Que.- For a given singly liked list of integers, sort the list using Merge Sort Algorithm.

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* merge(Node* first, Node* second) {
    Node* curr1 = first;
    Node* next1 = curr1 -> next;

    Node* curr2 = second;

    while(next1 != NULL && curr2 != NULL) {

        if(curr1 -> data <= curr2 -> data && curr2 -> data <= next1 -> data) {

            curr1 -> next = curr2;
            Node* next2 = curr2 -> next;
            curr2 -> next = next1;

            curr2 = next2;
            curr1 = curr1 -> next;
        }
        else {
            curr1 = next1;
            next1 = next1 -> next;
        }
    }

    if(next1 == NULL) {
        curr1 -> next = curr2;
    }

    return first;
}

Node* mergeSort(Node *head) {
    // base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    // break linked list in 2 halves
    Node* mid = findMiddle(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both halves
    if(right -> data <= left -> data) {
        return merge(right, left);
    }
    else {
        return merge(left, right);
    }
}
