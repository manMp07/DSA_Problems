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

//Que.- Given a binary tree. Find the size of its largest subtree that is a BST.
//      Note: Here Size is equal to the number of nodes in the BST.

class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root, int &ans) {
    //base case
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root -> data, right.maxi);
    currNode.mini = min(root -> data, left.mini);

    if(left.isBST && right.isBST && (left.maxi < root -> data && root -> data < right.mini)){
        currNode.isBST = true;
        ans = max(ans, currNode.size);
    }
    else
        currNode.isBST = false;

    return currNode;
}

int largestBST(Node * root){
    int maxSize = 0;
    info temp = solve(root, maxSize);

    return maxSize;
}