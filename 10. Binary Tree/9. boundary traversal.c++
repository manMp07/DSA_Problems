#include<iostream>
#include<vector>
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

//Que.- Given a Binary Tree, find its Boundary Traversal. The traversal should be 
//      in the following order: 
//      Left Boundary Nodes: defined as the path from the root to the left-most node
//      ie- the leaf node you could reach when you always travel preferring the left
//      subtree over the right subtree.
//      Leaf Nodes: All the leaf nodes except for the ones that are part of left or
//      right boundary.
//      Reverse Right Boundary Nodes: defined as the path from the right-most node 
//      to the root. The right-most node is the leaf node you could reach when you
//      always travel preferring the right subtree over the left subtree. Exclude
//      the root from this as it was already included in the traversal of left
//      boundary nodes.
//      Note: If the root doesn't have a left subtree or right subtree, then the
//      root itself is the left or right boundary.

// Time : O(N)
// Space : O(N)

void traveralLeft(Node*root, vector<int> &ans) {
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return;

    ans.push_back(root -> data);

    if(root -> left)    
        traveralLeft(root -> left, ans);
    else
        traveralLeft(root -> right, ans);
}

void traveralLeaf(Node*root, vector<int> &ans) {
    if((root == NULL))// || (root -> left == NULL && root -> right == NULL))
        return;

    if(root -> right == NULL && root -> left == NULL) {
        ans.push_back(root -> data);
        return;
    }

    traveralLeaf(root -> left, ans);
    traveralLeaf(root -> right, ans);
}

void traveralRight(Node*root, vector<int> &ans) {
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
        return;

    if(root -> right)
        traveralRight(root -> right, ans);
    else
        traveralRight(root -> left, ans);

    ans.push_back(root -> data);
}

vector<int> traverseBoundary(Node*root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    ans.push_back(root -> data);
    
    //store left boundary
    traveralLeft(root -> left, ans);

    //store leaf nodes
    //left subtree
    traveralLeaf(root -> left, ans);
    //right subtree
    traveralLeaf(root -> right, ans);

    //store right boundary in reverse order(back-tracking)
    traveralRight(root -> right, ans);

    return ans;
}