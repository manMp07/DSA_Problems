#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

//Que.- You have been given an integer singly Linked List. After every 'M' nodes,
//      you have to take the sum of the next 'N' nodes and append that sum to the 
//      Linked List. Do this till end of the linked list.
//
//      Note : In case the linked list ends after adding K nodes, where K is the any
//             position integer less than 'N'. Append the sum of those K nodes at the
//             end of the linked list.

Node* addNodes(Node* head, int n, int m) {
	if(head == NULL) {
		return head;
	}

	Node* curr = head;

	for(int i = 0; i < m; i++) {
		curr = curr -> next;

		if(curr == NULL)
			return head;
	}

	int sum = 0;
	for(int i = 0; i < n-1; i++) {
		
		if(curr -> next == NULL)
			break;

		sum += curr -> data;
		curr = curr -> next;
	}
	sum += curr->data;

	//insert sum
	Node* sumNode = new Node(sum);
	sumNode -> next = addNodes(curr -> next, n, m);
	curr -> next = sumNode;

	return head;
}