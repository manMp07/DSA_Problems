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

//Que.- Given a binary tree of size N. Your task is to complete the function
//      sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest
//      path from root to leaf node.
//      If two or more paths compete for the longest path, then the path having
//      maximum sum of nodes is being considered.

// Time : O(N)
// Space : O(N)

void solve(Node* root, int len, int &maxLen, int sum, int &maxSum) {
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;

    solve(root -> left, len+1, maxLen, sum, maxSum);
    solve(root -> right, len+1, maxLen, sum, maxSum);
}

int longestPath(Node *root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
}