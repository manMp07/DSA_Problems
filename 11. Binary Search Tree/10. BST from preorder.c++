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

//Que.- Given the preorder traversal of a binary search tree, construct the BST.

// Time : O(N*N)
// Space : O (N)

Node* insertIntoBST(Node* root, int val) {
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(root -> data < val)
        root -> right = insertIntoBST(root -> right, val);
    else
        root -> left = insertIntoBST(root -> left, val);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    Node* root = NULL;

    for(int i = 0; i < preorder.size(); i++) {
        root = insertIntoBST(root, preorder[i]);
    }

    return root;
}

// Time : O(NlogN)
// Space : O(N)
/*
step 1 : sort preorder to get inorder
step 2 : using preorder & inorder, create tree as we've done in binary tree
*/

// Time : O(N)
// Space : O(N)

Node* createBST(vector<int> &preorder, int lo, int hi, int &idx) {
    if(idx >= preorder.size())
        return NULL;
        
    if(preorder[idx] < lo || preorder[idx] > hi)
        return NULL;

    Node* root = new Node(preorder[idx++]);
    
    root -> left = createBST(preorder, lo, root -> data, idx);
    root -> right = createBST(preorder, root -> data, hi, idx);

    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int lo = INT_MIN;
    int hi = INT_MAX;
    int idx = 0;

    return createBST(preorder, lo, hi, idx);
}