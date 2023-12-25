#include<iostream>
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

//Que.- You are given a binary tree. You have to count and return the number of leaf
//      nodes present in it.

void inOrder(Node *root, int &count) {
    if(root == NULL)
        return;

    inOrder(root -> left, count);

    if(root -> left == NULL && root -> right == NULL)
        count++;

    inOrder(root -> right, count);
}

int noOfLeafNodes(Node *root){
    int count = 0;
    inOrder(root, count);

    return count;
}