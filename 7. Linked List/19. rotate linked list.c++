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

//Que.- Given the head of a linked list, rotate the list to the right by k places.

/*Input:
	head = [1,2,3,4,5] 
	k = 2
Output:
    head = [4,5,1,2,3]
*/

//Time : O(N)
//Space : O(1)

Node *rotate(Node *head, int k) {
    if(head == NULL||head->next == NULL||k == 0)
        return head;

    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }

    //link last Node to first Node
    temp->next = head;

    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list

    while(end--)
        temp = temp->next;

     //breaking last Node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
          
    return head;
}