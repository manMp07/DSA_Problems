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

//Que.- Given a Binary Tree, find the vertical traversal of it starting from the
//      leftmost level to the rightmost level.
//      If there are multiple nodes passing through a vertical line, then they
//      should be printed as they appear in level order traversal of the tree.

// Time : O(N*logN) bcoz we're using map & map take logN time to insert elements
// Space : O(N)

vector<int> verticalOrder(Node *root){   
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    map<int, vector<int>> node; // map<hd, list>
    queue<pair<Node*, int>> q; // q<node*, hd>
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*, int> temp=q.front();
        q.pop();

        Node* tempNode= temp.first;
        int hd= temp.second;

        node[hd].push_back(tempNode -> data);

        if(tempNode->left)
            q.push(make_pair(tempNode -> left, hd-1));

        if(tempNode->right)
            q.push(make_pair(tempNode -> right, hd+1));
    }

    for(auto i : node){
        for(auto j : i.second){
            ans.push_back(j);
        }
    }

    return ans;
}