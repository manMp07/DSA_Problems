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

//Que.- There is BST given with the root node with the key part as an integer only.
//      You need to find the in-order successor and predecessor of a given key. If
//      either predecessor or successor is not found, then set it to -1.

// Time : O(H)
// Space : O(H)

void solve(Node* root, int key, Node* &pred, Node* &succ) {
	if(root == NULL)
		return;
	
	if(root -> data == key) {
		if(root -> left){
			Node* temp = root -> left;
			while(temp -> right)
				temp = temp -> right;
			pred = temp;
		}
		if(root -> right){
			Node* temp = root -> right;
			while(temp -> left)
				temp = temp -> left;
			succ = temp;
		}
		return;
	}
	
	if(key < (root -> data)) {
		succ = root;
		solve(root -> left, key, pred, succ);
	}
	if(key > (root -> data)) {
		pred = root;
		solve(root -> right, key, pred, succ);
	}
}

vector<int> findPreSuc(Node *root, int key){
	vector<int> ans;
	
	Node* pred = NULL;
	Node* succ = NULL;
	
	solve(root, key, pred, succ);

	if(pred)
		ans.push_back(pred -> data);
	else
		ans.push_back(-1);

	if(succ)
		ans.push_back(succ -> data);
	else
		ans.push_back(-1);
	
	return ans;
}

/***Optimized Approach***/
// Time : O(N)
// Space : O(1)

pair<int, int> predecessorSuccessor(Node* root, int key){
    int pred = -1;
    int succ = -1;
    
    Node* temp = root;
    
    while(temp -> data != key) {
        if(temp -> data > key) {
            succ = temp -> data;
            temp = temp -> left;
        }
        
        if(temp -> data < key) {
            pred = temp -> data;
            temp = temp -> right;
        }
    }

    Node* leftTree = temp -> left;
    while(leftTree != NULL) {
        pred = leftTree -> data;
        leftTree = leftTree -> right;
    }

    Node* rightTree = temp -> right;
    while(rightTree != NULL) {
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }

    pair<int, int> ans = make_pair(pred, succ);

    return ans;
}