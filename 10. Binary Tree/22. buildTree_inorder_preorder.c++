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

//Que.- Given 2 Arrays of Inorder and Preorder traversal. The tree can contain
//      duplicate elements. Construct a binary tree.

// Time : O(N) Bcoz we used mapping to reduce time from N^2
// Space : O(N)

Node* solve(vector<int> in, vector<int> pre, unordered_map<int, int> nodeToIndex, int &index,
            int inStart, int inEnd, int n) {
    
    // base case
    if(index >= n || inStart > inEnd)
        return NULL;
    
    // create root node for elemenet
    int element = pre[index++];
    Node* root = new Node(element);

    // find element's index in inorder
    int pos = nodeToIndex[element];

    // recursive calls
    root -> left = solve(in, pre, nodeToIndex, index, inStart, pos-1, n);
    root -> right = solve(in, pre, nodeToIndex, index, pos+1, inEnd, n);

    return root;
}

Node *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){
    int n = preorder.size();
    int index = 0; // index must be passed by reference in this type of questions
    
    unordered_map<int, int> nodeToIndex;
    
    // create nodes to index mapping 
    for(int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i;
    }

	Node* ans = solve(inorder, preorder, nodeToIndex, index, 0, n-1, n);

    return ans;
}