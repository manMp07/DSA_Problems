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

//Que.- Given a Binary Tree, find Right view of it. Right view of a Binary Tree is
//      set of nodes visible when tree is viewed from right side.

// Time : O(N)
// Space : O(N)

void solve(Node* root, int level, vector<int> &ans) {
    if(root == NULL)
        return;

    //we entered into the new level
    if(ans.size() == level)
        ans.push_back(root -> data);

    solve(root -> right, level + 1, ans);
    solve(root -> left, level + 1, ans);
}

vector<int> getRightView(Node* root){
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}