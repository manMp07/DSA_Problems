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

//Que.- For given a binary tree, your task is to return inorder traversal of this
//      tree using stack data structure.

// Time : O(N)
// Space : O(N)

vector<int> getInOrderTraversal(Node *root){
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || s.empty() == false){
        while (curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top();
        s.pop();

        ans.push_back(curr -> data);
        curr = curr ->right;
    }
    return ans;
}