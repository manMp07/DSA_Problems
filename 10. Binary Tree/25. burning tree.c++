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

//Que.- Given a binary tree and a node data called target. Find the minimum time
//      required to burn the complete binary tree if the target is set on fire. It
//      is known that in 1 second all nodes connected to a given node get burned.
//      That is its left child, right child, and parent.
//      Note : The tree contains unique values

// Time : O(N*logN) for inserting map elements
// Space : O(N)

Node* createMapping(Node* root, int target, map<Node*,Node*> &nodeToParent) {
    Node* res = NULL;

    queue<Node*> q;
    q.push(root);

    nodeToParent[root] = NULL;

    while(!q.empty()) {
        Node* front = q.front();
        if(front -> data == target)
            res = front;

        q.pop();

        if(front -> left){
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }
        if(front -> right){
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return res;
}

void burnTree(Node* root, map<Node*, Node*> &nodeToParent, int &time) {
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    while(!q.empty()) {
        int size = q.size();

        bool flag = false;

        for(int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            
            if(front -> left && visited[front -> left] == false) {
                q.push(front -> left);
                visited[front -> left] = true;
                flag = true;
            }

            if(front -> right && visited[front -> right] == false) {
                q.push(front -> right);
                visited[front -> right] = true;
                flag = true;
            }

            if(nodeToParent[front] && visited[nodeToParent[front]] == false){
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
                flag = true;
            }
        }
        
        if(flag)
            time++;
    }
}

int timeToBurnTree(Node* root, int start){
    //Algo
    // step 1: create nodeToParent mapping
    // step 2: find target Node
    // step 3: burn the tree in min time

    int ans = 0;
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createMapping(root, start, nodeToParent);

    burnTree(targetNode, nodeToParent, ans);

    return ans;
}