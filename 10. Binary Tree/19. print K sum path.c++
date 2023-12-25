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

//Que.- You are given a binary tree contains an integer value and a number 'K'. Your
//      task is to print every path of the binary tree with the sum of nodes in the 
//      path as 'K'.

// Time : O(N^2)
// Space : O(N)

void getPath(Node* root, int target, vector<int> &path, vector<vector<int>> &result) {
    if(root == NULL)
        return;

    path.push_back(root -> data);

    getPath(root -> left, target, path, result);
    getPath(root -> right, target, path, result);

    int currSum = 0;
    for(int i = path.size()-1; i >= 0; i--){
        currSum += path[i];
        if(currSum == target)
            result.push_back(vector<int> (path.begin() + i, path.end()));
    }
    
    path.pop_back();
}

vector<vector<int>> kPathSum(Node* root, int k) {
    vector<vector<int>> result;
    vector<int> path;

    getPath(root, k, path, result);

    return result;
}