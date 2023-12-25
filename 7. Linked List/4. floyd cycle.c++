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

bool isCircular(Node* head) {
    //Que.- Check if the LL is circular or not.

    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != head && temp != NULL) {
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }
    return false;
    // This code will not work for LL which contains a loop in it.
}

bool detecteLoop(Node* head){
    //Que.- Check if there is a loop present in LL or not.

    if(head == NULL) {
        return true;
    }

    map <Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL) {
        // Loop is present
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;

    // Time : O(N)
    // Space : O(N)
}

Node* floydCycleDetection(Node* head) {
    //Que.- Return the node at fast & slow will intersect.

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast) {
            // It's not nessecery that slow & fast will overlap on starting node of loop
            // But if it is circular LL, then definitely they will overlap on head.
            return slow;
        }
    }
    return NULL;

    // Time : O(N)
    // Space : O(1)
}

Node* floydNodeDetection(Node* head) {
    //Que.- Return the starting node of the loop
    
    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydCycleDetection(head);
    if(intersection == NULL) {
        return NULL;
    }

    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

Node* removeLoop(Node* head) {
    //Que.- Remove the loop if present in LL and return the head of updated LL.

    if(head == NULL) {
        return NULL;
    }

    Node* firstNode = floydCycleDetection(head);
    if(firstNode == NULL) {
        return head;
    }

    Node* temp = firstNode;

    while(temp -> next != firstNode) {
        temp = temp -> next;
    }

    temp -> next = NULL;

    return head;
}