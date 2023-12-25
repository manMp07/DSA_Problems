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

//Que.- Given a binary tree and an integer K. Find the number of paths in the tree
//      which have their sum equal to K.
//      A path may start from any node and end at any node in the downward direction.

// Time : O(N^2)
// Space : O(N)

void solve(Node* root, int target, int &count, vector<int> path) {
    if(root == NULL)
        return;

    path.push_back(root -> data);

    solve(root -> left, target, count, path);
    solve(root -> right, target, count, path);

    int sum = 0;
    for(int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if(sum == target)
            count++;
    }
    
    path.pop_back();
}

int findSumPaths(Node* root, int target) {
    int count = 0;

    vector<int> path;

    solve(root, target, count, path);

    return count;
}


// Time : O(N)
// Space : O(N)

void countPaths(Node* root, int target, int currSum, unordered_map<int, int>& prefixSum, int& count) {
    if (!root)
        return;

    // Update the current sum
    currSum += root -> data;

    // If the currSum equals target, increment count
    if (currSum == target)
        count++;

    // Check if there exists a prefix sum (currSum - target) in the prefixSum map
    if (prefixSum.find(currSum - target) != prefixSum.end())
        count += prefixSum[currSum - target];

    // Update prefixSum with the currSum
    prefixSum[currSum]++;

    // Recursively traverse the left and right subtrees
    countPaths(root->left, target, currSum, prefixSum, count);
    countPaths(root->right, target, currSum, prefixSum, count);

    // Restore the prefixSum for backtracking
    prefixSum[currSum]--;
}

int findSumPaths(Node* root, int target) {
    unordered_map<int, int> prefixSum;
    int count = 0;
    int currSum = 0;

    countPaths(root, target, currSum, prefixSum, count);

    return count;
}