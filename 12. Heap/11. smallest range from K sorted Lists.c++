#include<bits/stdc++.h>
using namespace std;

//Que.- Given K sorted lists of integers, KSortedArray[] of size N each. The task
//      is to find the smallest range length that includes at least one element from each
//      of the K lists.

// Time : O(N*K*logK)
// Space : O(K)

class Node{
    public:
    int data;
    int row, col;

    Node(int data, int row, int col) {
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

int kSorted(vector<vector<int>> &arr, int k, int n) {
    // Idea is to check all ranges in minHeap itself, as minHeap will always be containing
    // at least one element from all k lists(Until any list gets completed).
    // We want minimum of all (pq.maxi - pq.mini + 1).

    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int maxElement = INT_MIN;

    //step1 : create minHeap for starting element of each lists
    for(int i = 0; i < k; i++) {
        maxElement = max(maxElement, arr[i][0]);

        Node* temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    //step2 : Process Ranges
    int minLength = INT_MAX;
    while(true) {
        // fetch minimum
        Node* top = minHeap.top(); minHeap.pop();
        int currRow = top -> row;
        int currCol = top -> col;

        // updating range
        int currLength = maxElement - top->data + 1;
        minLength = min(minLength, currLength);

        // next element exits
        if(currCol + 1 < n){
            maxElement = max(maxElement, arr[currRow][currCol + 1]);
            Node* next = new Node(arr[currRow][currCol + 1], currRow, currCol + 1);
            minHeap.push(next);
        }
        // next element dosen't exist
        else{
            break;
        }
    }

    return minLength;
}