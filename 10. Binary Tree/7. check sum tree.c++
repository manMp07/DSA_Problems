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

//Que.- Given a Binary Tree. Return true if, for every node X in the tree other
//      than the leaves, its value is equal to the sum of its left subtree's value
//      and its right subtree's value. Else return false.
//      An empty tree is also a Sum Tree as the sum of an empty tree can be
//      considered to be 0. A leaf node is also considered a Sum Tree.


// Time : O(N)
// Space : O(Height)
pair<bool, int> solve(Node* root) {
    //base case
    if(root == NULL) {
        pair<bool, int> ans = make_pair(true, 0);
        return ans;
    }

    //leaf node
    if(root -> left == NULL && root -> right == NULL) {
        pair<bool, int> ans = make_pair(true, root -> data);
        return ans;
    }

    pair<bool, int> left = solve(root -> left);
    pair<bool, int> right = solve(root -> right);

    bool sumCheck = (root -> data) == (left.second + right.second);

    pair<bool, int> ans;
    
    if(left.first && right.first && sumCheck) {
        ans.first = true;
        ans.second = 2 * (root -> data);
    }
    else {
        ans.first = false;
    }
    
    return ans;
}

bool isSumTree(Node* root){
    return solve(root).first;
}