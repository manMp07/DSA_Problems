#include<iostream>
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

// Time : O(N)
// Space : O(height) or O(N) in skew tree

int heightOfBinaryTree(Node* root){
	//base case
    if(root == NULL) {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(root -> left);
    int rightHeight = heightOfBinaryTree(root -> right);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}