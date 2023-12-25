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

//Que.- Given a binary tree, flatten it into linked list in-place. Usage of
//      auxiliary data structure is not allowed. After flattening, left of each node
//      should point to NULL and right should contain next node in preorder.

// Time : O(N)
// Space : O(1)

Node* findPred(Node* curr) {
    Node* pred = curr -> left;
    while(pred -> right) {
        pred = pred -> right;
    }
    return pred;
}

void flattenBinaryTree(Node* root){
    Node* curr = root;

    while(curr != NULL) {
        if(curr -> left){
            Node* pred = findPred(curr);
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
}

// Try rucursive approach also.
// Time : O(N)
// Space : O(N)