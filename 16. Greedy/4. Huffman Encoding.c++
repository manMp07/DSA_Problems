#include<bits/stdc++.h>
using namespace std;

//Que.- https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp {
    public:
    bool operator()(Node* a, Node*b){
        return a->data > b ->data;
    }
};

class Solution {
    public:
    void traverse(Node* root, vector<string>& ans, string temp) {
        // base case
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(temp);
            return;
        }
        
        traverse(root -> left, ans, temp+'0');
        traverse(root -> right, ans, temp+'1');
    }

    vector<string> huffmanCodes(string S,vector<int> f,int N){
        priority_queue<Node*, vector<Node*>, cmp> minHeap; //why this cmp is a class?
        
        for(int i = 0; i < N; i++){
            Node* temp = new Node(f[i]);
            minHeap.push(temp);
        }
        
        while(minHeap.size() > 1){
            Node* left = minHeap.top(); minHeap.pop();
            Node* right = minHeap.top(); minHeap.pop();
            
            Node* newNode = new Node(left->data + right->data);
            newNode -> left = left;
            newNode -> right = right;
            
            minHeap.push(newNode);
        }
        
        Node* root = minHeap.top();
        
        vector<string> ans;
        string temp = "";
        traverse(root, ans, temp);
        
        return ans;
    }
};