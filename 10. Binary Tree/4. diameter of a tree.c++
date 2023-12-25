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

//Que.- The diameter of a tree (sometimes called the width) is the number of nodes
//      on the longest path between two end nodes. The diagram below shows two trees
//      each with diameter nine, the leaves that form the ends of the longest path
//      are shaded (note that there is more than one path in each tree of length
//      nine, but no path longer than nine nodes).

// Time : O(N^2) because of calling 'height'.
int height(Node* root){
    if(root == NULL)
        return 0;

    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}

int diameter(Node* root) {
    if(root == NULL)
        return 0;

    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left) + 1 + height(root -> right);

    int diameter = max(op1, max(op2,op3));

    return diameter;
}


/*** 2ed Approach ***/
// Time : O(N)
// Space : O(Height)
pair<int, int> diameterFast(Node* root) {
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        return p;
    }
        
    pair<int,int> left = diameterFast(root -> left);
    pair<int,int> right = diameterFast(root -> right);
        
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
        
    pair<int, int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second, right.second) + 1;
        
    return ans;
}

int diameter(Node* root) {
    return diameterFast(root).first;
}