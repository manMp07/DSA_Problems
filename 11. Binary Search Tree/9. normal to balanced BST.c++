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

//Que.- Given a BST (Binary Search Tree) that may be unbalanced, convert it into a
//      balanced BST that has minimum possible height.
//      In balanced tree, the height of two subtrees of every node differs no more
//      than 1.

// Time : O(N)
// Space : O(N)

Node* createBST(vector<int> arr, int lo, int hi) {
    if(lo > hi)
        return NULL;

    int mid = lo + (hi - lo)/2;

    Node* temp = new Node(arr[mid]);

    temp -> left = createBST(arr, lo, mid-1);
    temp -> right = createBST(arr, mid+1, hi);

    return temp;
}

void inorder(Node* root, vector<int> &arr) {
    if(root == NULL)
        return;

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

Node* balancedBst(Node* root) {
    if(root == NULL)
        return NULL;

    // create array of sorted elements (inorder)
    vector<int> arr;
    inorder(root, arr);

    // create BST using this sorted elements by binary search
    int lo = 0;
    int hi = arr.size()-1;
    Node* newRoot = createBST(arr, lo, hi);

    return newRoot;
}