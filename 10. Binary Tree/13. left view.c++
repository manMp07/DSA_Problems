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

//Que.- Given a Binary Tree, return Left view of it. Left view of a Binary Tree is
//      set of nodes visible when tree is visited from Left side.


/*** Level Order Traversal ***/
// Time : O(N*logN) why?
// Space : O(N)

vector<int> getLeftView(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> leftNode; //map<level, data>

    queue<pair<Node*, int>> q; //pair<node*, level>

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int level = temp.second;

        
        if(leftNode.find(level) == leftNode.end())
            leftNode[level] = frontNode -> data;

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, level+1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, level+1));
    }

    for(auto i : leftNode)
        ans.push_back(i.second);

    return ans;
}


/*** Pre Order Traversal ***/
// Time : O(N)
// Space : O(N)

void solve(Node* root, int level, vector<int> &ans) {
    if(root == NULL)
        return;

    //we entered into the new level
    if(ans.size() == level)
        ans.push_back(root -> data);

    solve(root -> left, level+1, ans);
    solve(root -> right, level+1, ans);
}

vector<int> getLeftView(Node* root){
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}