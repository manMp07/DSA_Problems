#include <bits/stdc++.h>
using namespace std;

//Que.- Given K sorted arrays arranged in the form of a matrix. The task is to merge
//      them into one sorted array.

// Time : O(Nlog(K))
// Space : O(N) ; N = Total number of elements in matrix

class Node {
    public:
    int data;
    int row, col;

    Node(int data, int row, int col){
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

class compare{
    public:
    bool operator()(Node* first, Node* second){
        return first -> data > second -> data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k){
   priority_queue<Node*, vector<Node*>, compare> minHeap;

    //step1 : storing first element of every vector into minHeap;
    for(int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);

        minHeap.push(temp);
    }

    //step2
    vector<int> ans;
    while(!minHeap.empty()) {
        Node* temp = minHeap.top();
        int currRow = temp -> row;
        int currCol = temp -> col;

        ans.push_back(temp->data);
        minHeap.pop();
        
        if(currCol+1 < kArrays[currRow].size()) {
            Node* next = new Node(kArrays[currRow][currCol+1], currRow, currCol+1);
            minHeap.push(next);
        }
    }

    return ans;

}