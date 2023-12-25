#include<iostream>
using namespace std;

//Que.- Given a singly linked list. The objective is to determine the middle node of a
//      singly linked list. However, If the list has even number of nodes, return the second middle
//      node.

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

int getLength(Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* approach1(Node *head) {
    int len = getLength(head);

    for(int i = 0; i < len/2; i++) {
        head = head -> next;
    }
    return head;
}

Node* approach2(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}