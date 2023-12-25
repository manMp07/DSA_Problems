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

//Que.- You are given a binary tree having 'N' distinct nodes and an integer 'M'.
//      Your task is to return the postorder successor of 'M'.

// Time : O(N)
// Space : O(Height)

int postOrderTraversal(Node* parent, Node* child, int M){
    if(child == NULL)
        return -1;

    if(child -> data == M) {
        // Case 1: If parent right is null or give node 'M' is parent right then return parent
        // In LRN, 'R' not present than 'N' will be answer,
        // or 'R' is target Node than also 'N' is answer.
        
        if(parent -> right == NULL || parent -> right == child)
            return parent->data;
        
        // Case 2: If parent left is equal to given child 'M'
        else {
            // Find the first leftmost Leaf node in right subtree of parent
            Node* temp = parent -> right;
            while( temp -> left  || temp -> right ){
                if(temp -> left)
                    temp = temp -> left;
                else
                    temp = temp -> right;
            }
            return temp -> data;
        }
    }

    // Find given node in left subtree and return postorder successor in 'd'
    int d = postOrderTraversal(child, child -> left, M);
 
    // If given node 'M' is not found in left subtree then search in right subtree   
    if(d == -1)
        d = postOrderTraversal(child, child -> right, M);

    // Return d
    return d;
}

int postOrderSuccessor(Node* root, int M){
    if(root == NULL || root -> data == M)
        return -1;
    
    int ans = postOrderTraversal(NULL, root, M);
    
    return ans;
}