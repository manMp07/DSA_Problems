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

//Que.- Given below is a binary tree. The task is to print the top view of binary
//      tree. Top view of a binary tree is the set of nodes visible when the tree
//      is viewed from the top.

// Time : O(N*logN) why?
// Space : O(N)

vector<int> getTopView(Node *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;

    map<int, int> topNode; //map<hd, data>

    queue<pair<Node*,int>> q; //pair<node*, hd>

    q.push(make_pair(root, 0));

    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //when element didn't find, map.find(x) returns end position.
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;

        if(frontNode -> left)
            q.push(make_pair(frontNode -> left, hd-1));
        
        if(frontNode -> right)
            q.push(make_pair(frontNode -> right, hd+1));
    }

    for(auto i : topNode)
        ans.push_back(i.second);

    return ans;
}