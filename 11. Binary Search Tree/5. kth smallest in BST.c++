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

//Que.- Given a BST and an integer K. Find the Kth Smallest element in the BST.

/***Recursive Inorder***/
// Time : O(N)
// Space : O(N)

void solve(Node* root, int k, int &i, int &ans) {
    if(root == NULL) {
        i++;
        return;
    }

    solve(root -> left, k, i, ans);

    if(i == k) {
        i = INT_MAX;
        ans = root -> data;
        return;
    }

    solve(root -> right, k, i, ans);
}

int kthSmallest(Node* root, int k) {
    int i = 0;
    int ans = -1;
    solve(root, k, i, ans);

    return ans;
}

/***Using Morris Traversal***/
// Time : O(N)
// Space : O(1)

Node* findPred(Node* curr) {
    Node* temp = curr -> left;
    while(temp -> right && temp -> right != curr)
        temp = temp -> right;

    return temp;
}

int kthSmallest(Node *root, int k){
    Node* curr = root;
    int count = 0;
    
    while(curr != NULL) {
        if(curr -> left == NULL){
            count++;
            if(count == k)
                return curr -> data;
            curr = curr -> right;
        }
        else{
            Node* pred = findPred(curr);
            if(pred -> right == NULL){
                pred -> right = curr;
                curr = curr -> left;
            }
            else{
                count++;
                if(count == k)
                    return curr -> data;
                pred -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    
    return -1;
}