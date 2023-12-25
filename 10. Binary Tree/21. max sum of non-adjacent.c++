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

//Que.- Given a binary tree with a value associated with each node, we need to
//      choose a subset of these nodes such that sum of chosen nodes is maximum under
//      a constraint that no two chosen node in subset should be directly connected
//      that is, if we have taken a node in our sum then we can’t take its any
//      children or parents in consideration and vice versa.

// Time : O(N)
// Space : O(N)

pair<int, int> solve(Node *root) {
    pair<int, int> ans;
    
    if(root == NULL){
        ans = {0,0};
        return ans;
    }

    pair<int, int> leftAns = solve(root -> left);
    pair<int, int> rightAns = solve(root -> right);
    
    //include this node
    ans.first = root -> data + leftAns.second + rightAns.second;

    //exclude this node
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    
    return ans;
}

int maximumSumOfNodes(Node *root){
	pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}