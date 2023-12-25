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

//Que.- Given a Binary Tree with all unique values and two nodes value, n1 and n2.
//      The task is to find the lowest common ancestor of the given two nodes. We
//      may assume that either both X and Y are present in the tree or none of
//      them are present.
//      LCA : It is the first common ancestor of both the nodes n1 and n2 from bottom
//      of tree.

// Time : O(N)
// Space : O(N)

Node* lca(Node* root, int x, int y) {
    if(root == NULL)
        return NULL;

    if(root -> data == x || root -> data == y)
        return root;

    Node* leftAns = lca(root -> left, x, y);
    Node* rightAns = lca(root -> right, x, y);

    if(!leftAns && !rightAns)
        return NULL;

    if(!leftAns && rightAns)
        return rightAns;

    if(leftAns && !rightAns)
        return leftAns;
    
    if(leftAns && rightAns)
        return root;
}

int lowestCommonAncestor(Node *root, int x, int y){
    Node* ansNode = lca(root, x, y);

    return (ansNode->data);
}