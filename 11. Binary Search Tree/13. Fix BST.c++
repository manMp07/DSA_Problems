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

//Que.- You have been given a Binary Search Tree of 'N' nodes, where exactly two nodes of
//      the same tree were swapped by mistake.
//      Your task is to restore or fix the BST, without changing its structure and return
//      the root of the corrected BST.

//***Brute Force*** : Store inorder and sort it. Now place all the sorted values in actual tree.
// Time : O(N) + O(NlogN)
// Space : O(N); storing inorder

/*** Optimized ***/
//Time : O(N)
//Space : O(1); without call stacks

Node* first = NULL;
Node* middle = NULL;
Node* last = NULL;

void inorder(Node* root, Node* &prev){
    if(root == NULL)
        return;

    inorder(root -> left, prev);

    if(prev && prev -> data > root -> data){
        if(first == NULL){
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;

    inorder(root -> right, prev);
}

Node * FixBST(Node * root){
    Node* prev = NULL;
    inorder(root, prev);

    if(last)
        swap(first -> data, last -> data);
    else
        swap(first -> data, middle -> data);

    return root;
}