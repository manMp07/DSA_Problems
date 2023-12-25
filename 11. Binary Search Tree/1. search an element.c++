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

//Que.- Given a Binary Search Tree and a node value X, find if the node with value X
//      is present in the BST or not.

/***Recursie Approach***/
// Time : O(H)
// Space : O(N) for recursive calls

bool searchInBST(Node *root, int x) {
    if(root == NULL)
        return false;

    if(root -> data == x) 
        return true;

    if(x < root -> data)
        return searchInBST(root -> left, x);
        
    else
        return searchInBST(root -> right, x);
}

/***Iterative Approach***/
// Time : O(H)
// Space : O(1)

bool searchInBST(Node *root, int x) {
    
    Node* temp = root;
    while(temp != NULL){
        if(temp -> data == x) 
            return true;

        if(x < temp -> data)
            temp = temp -> left;

        else
            temp = temp -> right;
    }

    return false;
}