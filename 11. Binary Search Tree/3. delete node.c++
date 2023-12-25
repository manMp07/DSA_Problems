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

//Que.- Given a Binary Search Tree and a node value 'key'. Delete the node with the 
//      given value 'key' from the BST. If no node with value 'key' exists, then do
//      not make any change.

// Time : O(H)
// Space : O(H)

int maxValue(Node* root) {
    Node* temp = root;

    while(temp -> right) 
        temp = temp -> right;

    return temp -> data;
}

int minValue(Node* root) {
    Node* temp = root;

    while(temp -> left) 
        temp = temp -> left;
        
    return temp -> data;
}

Node* bstDelete(Node* root, int key) {
    //base case
    if(root == NULL)
        return root;

    // key found
    if(root -> data == key) {
        // 0 child
        if(!root -> left && !root -> right) {
            delete root;
            return NULL;
        }

        // 1 child at left
        if(root -> left && !root -> right) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // 1 child at right
        if(!root -> left && root -> right) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child
        if(root -> left && root -> right) {
            int minimum = minValue(root -> right);
            root -> data = minimum;
            root -> right = bstDelete(root -> right, minimum);
            return root;
        }
    }

    if(root -> data > key) {
        root -> left = bstDelete(root -> left, key);
        return root;
    }

    if(root -> data < key) {
        root -> right = bstDelete(root -> right, key);
        return root;
    }
}