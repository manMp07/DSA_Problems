#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//Que.- Given a BST, The task is to convert it to a sorted Doubly Linked List. 

// Time : O(N)
// Space : O(Height)

void solve(Node* root, Node* &head) {
    if(root == NULL)
        return;

    solve(root -> right, head);

    root -> right = head;
    if(head != NULL)
        head -> left = root;

    head = root;

    solve(root -> left, head);
}

Node* BSTtoDLL(Node* root) {
    Node* head = NULL;
    solve(root, head);

    return head;
}