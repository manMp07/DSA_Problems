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

//Que.- Given a Binary Search Tree and a target sum. Check whether there's a pair 
//      of Nodes in the BST with value summing up to the target sum.

//*** Storing inorder ***
// Time : O(N)
// Space : O(N)

Node* findPred(Node* curr) {
    Node* temp = curr -> left;

    while(temp -> right && temp -> right != curr)
        temp = temp -> right;

    return temp;
}

void morrisInorder(Node* root, vector<int> &inorder) {
    if(root == NULL)
        return;

    Node* curr = root;

    while(curr != NULL) {
        if(curr -> left == NULL) {
            inorder.push_back(curr -> data);
            curr = curr -> right;
        }
        else{
            Node* pred = findPred(curr);
            if(pred -> right == NULL) {
                pred -> right = curr;
                curr = curr -> left;
            }
            else {
                inorder.push_back(curr -> data);
                pred -> right = NULL;
                curr = curr -> right;
            }
        }
    }
}

bool twoSumInBST(Node* root, int target) {
    vector<int> inorder;

    // stores inorder sorted values
    morrisInorder(root, inorder);

    // use 2 pointer approach to check if pair exists
    int lo = 0;
    int hi = inorder.size()-1;

    while(lo < hi) {
        if(inorder[lo] + inorder[hi] == target)
            return true;
        
        if(inorder[lo] + inorder[hi] < target)
            lo++;
        else
            hi--;
    }
    return false;
}

//*** Two Pointers on BST itself ***
// Time : O(N)
// Space : O(H)

bool twoSumInBST(Node* root, int target) {
    // It stores the iterators for starting and ending indices
    stack<Node *> start, end;

    // It initialises the starting operator
    Node *currNode = root;
    while (currNode != NULL){
        start.push(currNode);
        currNode = currNode->left;
    }

    // It initialises the ending operator
    currNode = root;
    while (currNode != NULL){
        end.push(currNode);
        currNode = currNode->right;
    }

    // Using the two-pointer technique.
    while (start.top() != end.top()){

        // It stores the values at starting and end node data
        int val1 = start.top()->data;
        int val2 = end.top()->data;

        // If the sum of values = target, return true
        if (val1 + val2 == target)
            return true;

        // If the sum of values < target, then move to the next greatest closer value.
        if (val1 + val2 < target){
            currNode = start.top()->right;
            start.pop();
            while (currNode != NULL){
                start.push(currNode);
                currNode = currNode->left;
            }
        }

        // If the sum of values > target value, then move to the next smallest closer value .
        else{
            currNode = end.top()->left;
            end.pop();
            while (currNode != NULL){
                end.push(currNode);
                currNode = currNode->right;
            }
        }
    }

    // If no two nodes is found, return false
    return false; 
}