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

//Que.- Check if the given binary heap tree or not

// Time : O(N)
// Space : O(N)

int countNodes(Node* root) {
    if(root == NULL)
        return 0;

    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

bool isCBT(Node* root, int i, int cnt) {
    if(root == NULL)
        return true;

    if(i > cnt)
        return false;

    bool left = isCBT(root -> left, 2*i, cnt);
    bool right = isCBT(root -> right, 2*i+1, cnt);

    return left && right;
}

bool isMaxHeap(Node* root) {
    // leaf node
    if(root -> left == NULL && root -> right == NULL)
        return true;

    // only left node present
    else if(root -> right == NULL){
        return (root -> data >= root -> left -> data);
    }

    // both nodes present
    else {
        bool left = isMaxHeap(root -> left);
        bool right = isMaxHeap(root -> right);
        bool curr = (root->data >= root->left->data) && (root->data >= root->right->data);

        return left && right && curr;
    }
}

bool isBinaryHeapTree(Node* root) {
    int cnt = countNodes(root);

    return isCBT(root, 1, cnt) && isMaxHeap(root);
}