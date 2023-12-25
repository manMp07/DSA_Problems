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

//Que.- Given a BST, flatten it into sorted linked list. After flattening, left of
//      each node should point to NULL and right should contain next node.

// Time : O(N)
// Space : O(N)

void inorder(Node* root, vector<Node*> &arr) {
    if(root == NULL)
        return;

    inorder(root -> left, arr);
    arr.push_back(root);
    inorder(root -> right, arr);
}

Node* flatten(Node* root){
    vector<Node*> inorderVal;

    inorder(root, inorderVal);

    int n = inorderVal.size();
    for(int i = 0; i < n-1; i++) {
        inorderVal[i] -> right = inorderVal[i+1];
        inorderVal[i] -> left = NULL;
    }

    inorderVal[n-1] -> left = NULL;
    inorderVal[n-1] -> right = NULL;

    return inorderVal[0];
}

/***Optimized (without using extra data structure)***/
// Time : O(N)
// Space : O(N)

void inorder(Node* root, Node* &prev){
    if(root == NULL)
        return;

    inorder(root -> left, prev);
    
    prev -> right = root;
    prev -> left = NULL;
    prev = prev -> right;
    
    inorder(root -> right, prev);
}

Node *flatten(Node *root) {
    Node* prev = new Node(-1);
    Node* temp = prev;
    
    inorder(root, prev);
    prev -> left = NULL;
    prev -> right = NULL;
    
    return temp -> right;
}