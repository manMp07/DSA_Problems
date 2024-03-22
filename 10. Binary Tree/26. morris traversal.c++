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
    while(pred -> right != NULL && pred -> right != curr)
        pred = pred -> right;

    return pred;
}

Node* findPredPost(Node* curr){
    Node* pred = curr -> right;
    while(pred -> left != NULL && pred -> left != curr)
        pred = pred -> left;

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

vector<int> preorderTraversal(Node* root){
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL){
        if(curr -> left == NULL){
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        else{
            Node* pred = findPred(curr);
            if(pred -> right == NULL){
                ans.push_back(curr -> data);
                pred -> right = curr;
                curr = curr -> left;
            }
            else{
                pred -> right = NULL;
                curr = curr -> right;
            }
        }
    }

    return ans;
}

vector<int> morrisPostorder(Node* root){
    /*PostOrder = LRN
    So we'll find NRL and it's reverse is the answer*/

    vector<int> ans;
    Node* curr = root;
 
    while(curr != NULL){
        if (curr -> right == NULL) {
            ans.push_back(curr -> data);
            curr = curr -> left;
        }
        else {
            Node* pred = findPredPost(curr);

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

    reverse(ans.begin(), ans.end());
    return ans;
}