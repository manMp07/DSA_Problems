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

//Que.- Given a Linked List which has data members sorted in ascending order. Create
//      a Balanced BST which has same data members as the given Linked List.

// Time : O(N)
// Space : O(N)

int countNode(Node* head){
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL) {
        cnt++;
        temp = temp -> right;
    }

    return cnt;
}

Node* solve(Node* &head, int n) {
    if(n <= 0 || head == NULL)
        return NULL;

    Node* left = solve(head, n/2);

    Node* root = head;
    root -> left = left;

    head = head -> right;

    root -> right = solve(head, n-(n/2)-1);

    return root;
}

Node* sortedListToBST(Node* head) {
    int n = countNode(head);
    Node* root = solve(head, n);

    return root;
}