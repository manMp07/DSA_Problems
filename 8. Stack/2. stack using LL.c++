#include<iostream>
using namespace std;

// Stack implementation using Linked List

class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    Node* head = NULL;
    public:
    int getSize(){
        int size = 0;
        Node* temp = head;
        while(temp != NULL) {
            size++;
            temp = temp -> next;
        }
        return size;
    }

    bool isEmpty(){
        if(head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int data){
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

    void pop(){
        if(head != NULL) {
            Node* temp = head -> next;
            head -> next = NULL;
            delete head;
            head = temp;
        }
    }

    int getTop(){
        if(head != NULL) {
            return head -> data;
        }
        else {
            return -1;
        }
    }
};

int main() {

    Stack st;
    st.push(6);
    st.push(14);
    st.push(22);

    st.pop();
    cout << st.getTop() << endl;

    cout << st.getSize() << endl;

    if(st.isEmpty()) {
        cout << "Stack is empty mere dost!" << endl;
    }
    else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}