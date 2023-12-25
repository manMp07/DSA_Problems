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

//Que.- Given a Binary Tree. Find the Zig-Zag Level Order Traversal of that Tree.

// Time : O(N)
// Space : O(N)

// Queue Approach
vector<int> zigZagTraversal(Node *root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {

        int size = q.size();
        vector<int> currentLevelNodes(size); // size of that level

        for(int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            currentLevelNodes[index] = frontNode -> data;

            if(frontNode -> left)
                q.push(frontNode -> left);

            if(frontNode -> right)
                q.push(frontNode -> right);
        }

        leftToRight = !leftToRight;

        for(auto i : currentLevelNodes) {
            ans.push_back(i);
        }
    }

    return ans;
}

// Two Stack Approach
vector<int> zigZagTraversal(Node *root){
    vector<int> result;

    if(root == NULL)
        return result;

    stack<Node*> oddLevel, evenLevel;
    oddLevel.push(root);

    while(!oddLevel.empty() || !evenLevel.empty()) {
        
        while(!oddLevel.empty()) {
            Node* topNode = oddLevel.top();
            oddLevel.pop();
            result.push_back(topNode -> data);

            if(topNode -> left)
                evenLevel.push(topNode -> left);

            if(topNode -> right)
                evenLevel.push(topNode -> right);
        }

        while(!evenLevel.empty()) {
            Node* topNode = evenLevel.top();
            evenLevel.pop();
            result.push_back(topNode -> data);

            if(topNode -> right)
                oddLevel.push(topNode -> right);

            if(topNode -> left)
                oddLevel.push(topNode -> left);
        }
    }

    return result;
}