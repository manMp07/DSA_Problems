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

//Que.- Given the root of a binary tree. Check whether it is a BST or not.

// Why this code is not working for all test cases?
//Ans.- The issue is that it checks the current node against only its immediate
//      left and right children, but it doesn't ensure that all nodes in the left
//      subtree are less than the current node's value or that all nodes in the
//      right subtree are greater than the current node's value.
bool validateBST(Node* root) {
    //Wrong approach
    if(root == NULL)
        return true;

    bool leftSub;
    if(root -> left)
        leftSub = (root->data >= root->left->data) && validateBST(root -> left);
    else
        leftSub = true;

    bool rightSub;
    if(root -> right)
        rightSub = (root->data <= root->right->data) && validateBST(root -> right);
    else
        rightSub = true;

    return leftSub && rightSub;
}

// Time : O(N)
// Space : O(H)

bool isBST(Node* root, int min, int max) {
    if(root == NULL)
        return true;

    if( (min <= root->data) && (root->data <= max) ) {
        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);

        return left && right;
    }
    return false;
}

bool validateBST(Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

/***Inorder approach***/
// Time : O(N)
// Space : O(H)

bool helper(Node* root, Node* &prev) {
    if(root == NULL)
        return true;

    if (helper(root->left, prev) == false)
        return false;

    if (prev != NULL && root->data < prev->data)
        return false;

    prev = root;
    return helper(root->right, prev);
}

bool validateBST(Node* root) {
    Node* prev = NULL;
    return (helper(root, prev));
}