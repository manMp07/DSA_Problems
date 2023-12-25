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

//Que.- Given a Binary Tree, print the diagonal traversal of the binary tree.

//Note : If the diagonal element are present in two different subtress then left
//       subtree diagonal element should be taken first and then right subtree.

// Time : O(N*logN)
// Space : O(N)

void preOrder(Node* root, map<int, vector<int>> &diagonal, int hd) {
    if(root == NULL)
        return;
        
    diagonal[hd].push_back(root -> data);
    preOrder(root -> left, diagonal, hd+1);
    preOrder(root -> right, diagonal, hd);
}

vector<int> diagonalTraversal(Node* root) {
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    map<int, vector<int>> diagonal;
    
    // We can't use level order traversal(read note from question)
    preOrder(root, diagonal, 0);

    for(auto i : diagonal) {
        for(auto j : i.second) {
            ans.push_back(j);
        }
    }

    return ans;
}