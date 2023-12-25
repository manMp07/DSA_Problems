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

//Que.- Given 2 Arrays of Inorder and postorder traversal. The tree can contain
//      duplicate elements. Construct a binary tree.

// Time : O(N*N) we can reduce it by using mapping
// Space : O(N)

int findPosition(vector<int> inorder, int key, int n) {
    for(int i = 0; i < n; i++) {
        if(inorder[i] == key)
            return i;
    }
    return -1;
}

Node* solve(vector<int> in, vector<int> post, int &index, int inStart, int inEnd, int n) {
    if(index < 0 || inStart > inEnd)
        return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);

    int pos = findPosition(in, element, n);

    //In case of inorder & postorder, we bild right subtree first.
    root -> right = solve(in, post, index, pos+1, inEnd, n);
    root -> left = solve(in, post, index, inStart, pos-1, n);

    return root;
}

Node* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder){
    int n = postorder.size();
    int index = n-1;
	Node* ans = solve(inorder, postorder, index, 0, n-1, n);

    return ans;
}