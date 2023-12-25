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

//Que.- Given a binary search tree which is also a complete binary tree. The problem
//      is to convert the given BST into a Min Heap with the condition that all the
//      values in the left subtree of a node should be less than all the values in
//      the right subtree of the node. This condition is applied to all the nodes,
//      in the resultant converted Min Heap.
//      Hint : Tree structure will remain same

// Time : O(N)
// Space : O(N)

void inorder(Node* root, vector<int> &arr) {
	if(root == NULL)
		return;

	inorder(root -> left, arr);
	arr.push_back(root->data);
	inorder(root -> right, arr);
}

void buildMinHeap(Node* &root, vector<int> arr, int &index) {
	if(root == NULL)
		return;

	root -> data = arr[index];
	index = index + 1;
	buildMinHeap(root -> left, arr, index);
	buildMinHeap(root -> right, arr, index);
}

Node* convertBST(Node* root){
    // step1 : store inorder(sorted array)
	vector<int> arr;
	inorder(root, arr);
	int index = 0;

    // step2 : update node values in same tree
	buildMinHeap(root, arr, index);

	return root;
}