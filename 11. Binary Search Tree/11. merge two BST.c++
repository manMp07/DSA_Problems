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

//Que.- Given two BSTs, return root of merged this two BSTs.

// Approach #1
// Time : O(N+M)
// Space : O(N+M)

Node* createBST(vector<int> &arr, int lo, int hi) {
    if(lo > hi)
        return NULL;

    int mid = lo + (hi - lo)/2;

    Node* temp = new Node(arr[mid]);

    temp -> left = createBST(arr, lo, mid-1);
    temp -> right = createBST(arr, mid+1, hi);

    return temp;
}

void mergeList(vector<int> &t1, vector<int> &t2, vector<int> &ans) {
    int i = 0;
    int j = 0;

    while(i < t1.size() && j < t2.size()) {
        if(t1[i] > t2[j])
            ans.push_back(t2[j++]);
        
        else
            ans.push_back(t1[i++]);
    }

    while(i < t1.size())
        ans.push_back(t1[i++]);

    while(j < t2.size())
        ans.push_back(t2[j++]);
}

void inorder(Node* root, vector<int> &arr) {
    if(root == NULL)
        return;

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

Node* mergeBST(Node *root1, Node *root2){
    // step 1 : store inorder
    vector<int> tree1, tree2;
    inorder(root1, tree1);
    inorder(root2, tree2);

    // step 2 : merged both sorted arrays
    vector<int> ans;
    mergeList(tree1, tree2, ans);

    // step 3 : used merged inorder array to build BST
    int lo = 0;
    int hi = ans.size()-1;
    Node* newRoot = createBST(ans, lo, hi);
    return newRoot;
}


// Approach #2
// Time : O(N+M)
// Space : O(H1 + H2)

int countNode(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL) {
        cnt++;
        temp = temp -> right;
    }

    return cnt;
}

Node* sortedLL_to_BST(Node* head, int n) {
    if(n <= 0 || head == NULL)
        return NULL;

    Node* left = sortedLL_to_BST(head, n/2);

    Node* root = head;
    root -> left = left;

    head = head -> right;

    root -> right = sortedLL_to_BST(head, n-(n/2)-1);

    return root;
}

Node* mergeSortedDLL(Node* h1, Node* h2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(h1 != NULL && h2 != NULL) {
        if(h1 -> data < h2 -> data){
            if(head == NULL)
                head = h1;
            else {
                tail -> right = h1;
                h1 -> left = tail;
            }
            tail = h1;
            h1 = h1 -> right;
        }
        else {
            if(head == NULL)
                head = h2;
            else {
                tail -> right = h2;
                h2 -> left = tail;
            }
            tail = h2;
            h2 = h2 -> right;
        }
    }

    while(h1 != NULL) {
        tail -> right = h1;
        h1 -> left = tail;
        tail = h1;
        h1 = h1 -> right;
    }

    while(h1 != NULL) {
        tail -> right = h2;
        h2 -> left = tail;
        tail = h2;
        h2 = h2 -> right;
    }
    
    return head;
}

void convertInto_SortedDLL(Node* root, Node* &head) {
    if(root == NULL)
        return;

    convertInto_SortedDLL(root -> right, head);

    root -> right = head;
    if(head != NULL)
        head -> left = root;

    head = root;

    convertInto_SortedDLL(root -> left, head);
}

Node* mergeBST(Node* root1, Node* root2){

    //step 1 : convert BST to sorted DLL in-place.
    Node* head1 = NULL;
    convertInto_SortedDLL(root1, head1);
    head1 -> left = NULL;

    Node* head2 = NULL;
    convertInto_SortedDLL(root2, head2);
    head2 -> left = NULL;

    //step 2 : merge two sorted DLL.
    Node* head = mergeSortedDLL(head1, head2);

    //step 3 : convert sorted LL to BST
    int n = countNode(head);
    Node* root = sortedLL_to_BST(head, n);

    return root;
}