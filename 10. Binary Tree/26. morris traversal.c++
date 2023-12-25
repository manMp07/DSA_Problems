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

//Que.- Morris traversal for inorder

// Time : O(N)
// Space : O(1)

Node* findPred(Node* curr) {
    Node* pred = curr -> left;
    while(pred -> right != NULL && pred -> right != curr) {
        pred = pred -> right;
    }
    return pred;
}

vector<int> morrisInorder(Node* root) {
    vector<int> ans;

    if(root == NULL)
        return ans;

    Node* curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        else{
            Node* pred = findPred(curr);

            if(pred -> right == NULL) { // means left part traverse krna baaki hai
                pred -> right = curr;
                curr = curr -> left;
            }

            //left part traverse ho gaya hai
            else{
                ans.push_back(curr -> data);
                pred -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return ans;
}

vector<int> morrisPreorder(Node* root){
    vector<int> ans;

    if(root == NULL)
        return ans;

    Node* curr = root;

    while(curr != NULL) {
        ans.push_back(curr -> data);

        if(curr -> left == NULL) {
            curr = curr -> right;
        }
        else{
            Node* pred = findPred(curr);

            if(pred -> right == NULL) {
                pred -> right = curr -> right;
                curr = curr -> left;
            }
        }
    }
    return ans;
}

vector<int> morrisPostorder(Node* root){
    vector<int> ans;
    Node* curr = root;
 
    while(curr != NULL){
        if (curr -> right == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> left;
        }
        else {
            Node* pred = findPred(curr);

            if (pred -> left == NULL) {
                ans.push_back(curr -> data);
                pred -> left = curr;
                curr = curr -> right;
            }
            else {
                pred -> left = NULL;
                curr = curr -> left;
            }
        }
    }
    return ans;
}