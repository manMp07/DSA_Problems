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

//Que.- Given a Binary Search Tree and two node 'P' & 'Q'. Find the Lowest Common
//      Ancestors of the two nodes in the BST.

// Time : O(N)
// Space : O(1)

Node* LCAinaBST(Node* root, Node* P, Node* Q){
    Node* curr = root;

    while(curr != NULL) {
        if(curr -> data < P -> data && curr -> data < Q -> data)
            curr = curr -> right;

        else if(curr -> data > P -> data && curr -> data > Q -> data)
            curr = curr -> left;

        else
            return curr;
    } 

    return NULL;
}