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

//Que.- Given a binary tree, find if it is height balanced or not. 
//      A tree is height balanced if difference between heights of left and right
//      subtrees is not more than one for all nodes of tree.

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int rightHight = height(root -> left);
    int leftHeight = height(root -> right);

    int ans = max(rightHight, leftHeight) + 1;

    return ans;
}

/***1st Approach***/
// Time : O(N^2)
// Space ; O(height)
bool isBalancedBT(Node* root){
    if(root == NULL)
        return true;

    bool left = isBalancedBT(root -> left);
    bool right = isBalancedBT(root -> right);

    bool diff = abs(height(root -> left) - height(root -> right)) <= 1;

    if(left && right && diff)
        return true;
    else
        return false;
}

/***2ed approach***/
// Time : O(N)
// Space : O(N)
pair<bool, int> isBalancedFast(Node* root) {
    if(root == NULL){
        pair<bool, int> ans = make_pair(true, 0);
        return ans;
    }

    pair<bool, int> left = isBalancedFast(root -> left);
    pair<bool, int> right = isBalancedFast(root -> right);

    bool leftCheck = left.first;
    bool rightCheck = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    
    if(leftCheck && rightCheck && diff)
        ans.first = true;
    else
        ans.second = false;

    return ans;
}

bool isBalancedBT(Node* root){
    return isBalancedFast(root).first;
}