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

//Que.- Given a binary tree of size  N, a node, and a positive integer k., Your task
//      is to complete the function kthAncestor(), the function should return the
//      kth ancestor of the given node in the binary tree. If there does not exist
//      any such ancestor then return -1.

/***Using Vector to Store Path***/
// Time : O(N+K)
// Space : O(N)

bool solve(Node *root, int targetNodeVal, vector<int> &ancestor) {
    if(root == NULL)
        return false;

    if(root -> data == targetNodeVal) {
        ancestor.push_back(root -> data);
        return true;
    }

    if(solve(root -> left, targetNodeVal, ancestor)){
        ancestor.push_back(root -> data);
        return true;
    }

    if(solve(root -> right, targetNodeVal, ancestor)){
        ancestor.push_back(root -> data);
        return true;
    }

    return false;
}

int findKthAncestor(Node *root, int targetNodeVal, int k) {
    vector<int> ancestor;

    solve(root, targetNodeVal, ancestor);

    for(int i = 1; i < ancestor.size(); i++) {
        if(i == k)
            return ancestor[i];
    }

    return -1;
}

/***Optimized Approach***/
// Time : O(N)
// Space : O(N)

Node* solve(Node *root, int targetNodeVal, int &k) {
    if(root == NULL)
        return NULL;

    if(root -> data == targetNodeVal){
        k--;
        return root;
    }

    Node* left = solve(root -> left, targetNodeVal, k);
    Node* right = solve(root -> right, targetNodeVal, k);

    if(left && !right){
        if(k == 0) {
            k--;
            return root;
        }
        k--;
        return left;
    }
    
    if(!left && right){
        if(k == 0) {
            k--;
            return root;
        }
        k--;
        return right;
    }

    if(!left && !right)
        return NULL;
}

int findKthAncestor(Node *root, int targetNodeVal, int k) {
    Node* ansNode = solve(root, targetNodeVal, k);
    
    if(k < 0)
        return ansNode -> data;
        
    return -1;
}