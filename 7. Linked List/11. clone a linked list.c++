#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;
    
    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;
    }

    ~Node() {
        int value = this->data;
        // memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

//Que.- You are given a linked list containing 'N' nodes where every node in the linked list
//      coontains two pointers:
//      i) 'next' which points to the next node in the list
//      ii) 'random' which points to a random node in the list or 'NULL'
//      Your task is to create a 'deep copy' of the given linked list

void insertAtTail(Node* &head, Node* &tail, int data) {
	Node* nodeToInsert = new Node(data);
	if(head == NULL) {
		head = nodeToInsert;
		tail = nodeToInsert;
		return;
	}
	tail -> next = nodeToInsert;
	tail = nodeToInsert;
}

Node *cloneList(Node *head) {
	// step-1 : create clone
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;

	Node* temp = head;
	while(temp != NULL) {
		insertAtTail(cloneHead, cloneTail, temp -> data);
		temp = temp -> next;
	}

	// step-2 : create a map
	unordered_map<Node*, Node*> oldToNew;

	Node* originalNode = head;
	Node* cloneNode = cloneHead;

	while (originalNode != NULL) {
		oldToNew[originalNode] = cloneNode;

		originalNode = originalNode -> next;
		cloneNode = cloneNode -> next;
	}
	
	
	// step-3 : arrange random pointers
	originalNode = head;
	cloneNode = cloneHead;

	while(cloneNode != NULL) {
		cloneNode -> random = oldToNew[originalNode -> random];

		cloneNode = cloneNode -> next;
		originalNode = originalNode -> next;
	}

	// step-4 : return ans
	return cloneHead;

	// Time : O(N)
	// Space : O(N)
}

Node *cloneList2(Node *head){

    // step-1 : create clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
        
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    }
        
    // step-2 : add clonenodes in between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while(originalNode != NULL) {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;
        
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }
    
	// step-3 : copy random pointers
    Node* curr = head;
    while(curr != NULL) {
        curr -> next -> random = curr -> random ? curr -> random -> next : curr -> random;
        
        curr = curr -> next -> next;
    }

    // step-4 : revert changes done in step-2
    originalNode = head;
    cloneNode = cloneHead;
    
    while(originalNode != NULL) {
        
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        
        if(originalNode != NULL) {
            cloneNode -> next = originalNode -> next;                
        }
        cloneNode = cloneNode -> next;
    }
    
    // step-5 : return ans
    return cloneHead;

	// Time : O(N)
	// Space : O(1)
}
