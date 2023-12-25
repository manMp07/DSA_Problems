#include<iostream>
#include<queue>
#include<stack>
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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Previous level is traversed completely
        if(temp == NULL) {
            cout << endl;
            //queue still has some child node
            if(!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) 
                q.push(temp -> left);

            if(temp -> right)
                q.push(temp -> right);
            
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    stack <Node *> S;
    queue <Node *> Q;
    Q.push(root);
 
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a Node, we push the Node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue Node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}

void inOrder(Node* root) {
    if(root == NULL)
        return;

    // L-N-R
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(Node* root) {
    if(root == NULL)
        return;

    // N-L-R
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node* root) {
    if(root == NULL)
        return;

    // L-R-N
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

/*** HW ***
1. Reverse order traversal
2. Inorder, preorder, postorder traversal using iteration
*/

// Iterative approach (using stack)
// Time : O(N)
// Space : O(N)
vector<int> inOrderTraversal(Node *root){
    vector<int> answer;
    if (root == NULL)
        return answer;

    stack<Node*> s;
    Node* current = root;

    while (current != NULL || s.empty() == false){
        while (current != NULL){
            s.push(current);
            current = current -> left;
        }
        current = s.top();
        s.pop();

        answer.push_back(current -> data);
        current = current ->right;
    }
    return answer;
}