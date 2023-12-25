#include<iostream>
using namespace std;

//Que.- Design a data structure to implement a circular queue of size N.

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
        this -> size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        //whether queue is full or not
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1)) ) {
            cout << "Queue is Full" << endl;
            return;
        }

        if(front == -1) {//first element to push
            front = 0;
            rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0; // to maintain cyclic nature
        }
        else { //Normal flow
            rear++;
        }

        arr[rear] = data;
    }

    int pop(){

        //whether queue is empty or not
        if(front == -1 && rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int val = arr[front];
        arr[front] = -1;

        if(front == rear) {
            front = rear = -1;
        }
        else if(front == size-1) {
            front = 0; // to maintain cyclic nature
        }
        else{//normal flow
            front++;
        }

        return val;
    }
};