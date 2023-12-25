#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

//Que.- Given a singly linked list, remove all the nodes in the list which have any
//      node on their right whose value is greater. (Not just immidiate Right , but
//      entire List on the Right)

// LinkedList = 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2 -> 3
// Output: 15 11 6 3

Node* reverse(Node* head) {
    if(head == NULL || head -> next == NULL)
        return head;
        
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
        
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
        
    return prev;
}

Node *compute(Node *head){
    if(head == NULL)
        return head;
        
    head = reverse(head);
        
    int maxi = head -> data;
        
    Node* curr = head;
        
    while(curr -> next != NULL) {
        if(curr -> next -> data < maxi) {
            Node* temp = curr -> next;
            curr -> next = curr -> next -> next;
                
            temp -> next = NULL;
            delete temp;
        }
        else {
            maxi = curr -> next -> data;
            curr = curr -> next;
        }  
    }
        
    head = reverse(head);
        
    return head;
}