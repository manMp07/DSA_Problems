#include<iostream>
#include<vector>
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

//Que.- Given a singly linked list of size N of integers. The task is to check if the given
//      linked list is palindrome or not.

bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL) {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    int s = 0;
    int e = arr.size() - 1;

    while(s <= e) {
        if(arr[s] == arr[e]) {
            s++;
            e--;
        }
        else {
            return false;
        }
    }
    return true;

    // Time : O(N)
    // Space : O(N)
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
        
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
        
    return slow;
}

Node* reverse(Node* head) {
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

//Function to check whether the list is palindrome.
bool isPalindrome2(Node *head){
    if(head == NULL || head -> next == NULL){
        return true;
    }
    
    //step-1 : find middle
    Node* mid = findMiddle(head);
    
    //step-2 : reverse list after middle
    mid -> next = reverse(mid -> next);
    
    //step-3 : compare both halves
    Node* temp1 = head;
    Node* temp2 = mid -> next;
        
    while(temp2 != NULL) {
        if(temp1-> data != temp2 -> data) {
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
        
    return true;

    // Time : O(N)
    // Space : O(N)
}