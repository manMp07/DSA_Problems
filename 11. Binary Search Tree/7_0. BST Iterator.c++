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

/**Que. Implement the BSTIterator Class.

BSTIterator(TreeNode root) : Initializes an object of the BSTIterator class. The root of the
BST is given as part of the constructor. The pointer should be initialized to a non-existent
number smaller than any element in the BST.

boolean hasNext() : Returns true if there exists a number in the traversal to the right of the
pointer, otherwise returns false.

int next() : Moves the pointer to the right, then returns the number at the pointer.
*/

class BSTIterator {
    stack<Node*> st;
    void pushAllLeft(Node* root){
        while(root){
            st.push(root);
            root = root -> left;
        }
    }

    public:
    BSTIterator(Node* root) {
        pushAllLeft(root);
    }
    
    int next() {
        Node* nextVal = st.top();
        st.pop();
        
        pushAllLeft(nextVal -> right);
        return nextVal -> data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};