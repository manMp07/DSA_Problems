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

//Que.- Given a binary tree, print the bottom view from left to right.
//      A node is included in bottom view if it can be seen when we look at the tree
//      from bottom.

// Time : O(N*logN) why?
// Space : O(N)

vector<int> getTopView(Node *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> bottomNode; //map<hd, data>

    queue<pair<Node*,int>> q; //pair<node*, hd>

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode -> data;

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }

    for(auto i : bottomNode)
        ans.push_back(i.second);

    return ans;
}