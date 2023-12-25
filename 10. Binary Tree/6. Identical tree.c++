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

//Que.- Given two binary trees, the task is to find if both of them are identical
//      or not.


// Time : O(N)
// Space : O(Height)
bool identicalTrees(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 == NULL && root2 != NULL)
        return false;

    if(root1 != NULL && root2 == NULL)
        return false;

    if(root1 -> data != root2 -> data) {
        return false;
    }

    bool left = identicalTrees(root1 -> left, root2 -> left);
    bool right = identicalTrees(root1 -> right, root2 -> right);

    bool ans = left && right;

    return ans;
}