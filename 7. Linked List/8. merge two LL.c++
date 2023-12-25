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

//Que.- You are given two sorted linked list. You have to merge them to produce a combained
//      sorted linked list. You need to return the head of final linked list.

Node* solve(Node* &first, Node* &second) {
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;

    while(next1 != NULL && curr2 != NULL) {
        if(curr1 -> data <= curr2 -> data && curr2 -> data <= next1 -> data) {
            // node addition
            curr1 -> next = curr2;
            Node* next2 = curr2 -> next;
            curr2 -> next = next1;

            // update pointers
            curr2 = next2;
            curr1 = curr1 -> next;
        }
        else {
            //curr1 & next1 ko aage badhana hai
            curr1 = next1;
            next1 = next1 -> next;
        }
    }
    if(next1 == NULL)
        curr1 -> next = curr2;
    
    return first;
}

Node* sortTwoLists(Node* first, Node* second){
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    if(first -> data <= second -> data)
        return solve(first, second);
    else
        return solve(second, first);
}