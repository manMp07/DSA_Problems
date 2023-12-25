#include<iostream>
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

//Que.- You have been given a singly Linked List containing integers. Your task is
//      to arrange all odd number first followed by even numbers sequentially.

Node * segregateOddEven(Node* head){
	if(head == NULL) {
		return head;
	}

	//create dummy node
	Node* dummy = new Node(1);
	dummy -> next = head;

	//positioning curr & prev
	Node* curr = head;
	Node* prev = dummy;
	Node* temp = dummy;

	//traversing the whole Linked List
	while(curr != NULL) {
		int curr_num = curr -> data;

		//for odd numbers
		if(curr_num % 2 == 1) {

			//if previous all elements are odd, we don't need to do anything
			if(prev->data % 2 == 1) {
				prev = curr;
				curr = curr -> next;
				continue;
			}

			//set temp pointer to the previous node of the even node
			while(temp != curr && temp -> next -> data % 2 != 0) {
				temp = temp -> next;
			}

			prev -> next = curr -> next;
			curr -> next = temp -> next;
			temp -> next = curr;
			curr = prev -> next;
		}

		// curr_num if even
		else {
			prev = curr;
			curr = curr -> next;
		}
	}

	return dummy -> next;
}