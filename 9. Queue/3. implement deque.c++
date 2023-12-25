#include<iostream>
using namespace std;

//Que.- Design a data structure to implement deque of size N.

class Deque{
    
    public:
    int* arr;
    int front;
    int rear;
    int size;

    Deque(int n){
        this -> size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){
        if(isFull())  {
            return false;
        }

        if(isEmpty()) {//first element
            front = rear = 0;
        }

        else if(front == 0 && rear != size-1){
            front = size - 1;
        }

        else {
            front--;
        }

        arr[front] = x;

        return true;
    }

    bool pushRear(int x){
        if(isFull()) {
            return false;
        }

        if(isEmpty()) { //first element
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;

        return true;
    }

    int popFront(){
        if(front == -1) {
            return -1;
        }

        int val = arr[front];
        arr[front] = -1;

        if(front == rear) {
            front = rear = -1;
        }
        else if (front == size-1) {
            front = 0;
        }
        else{
            front++;
        }

        return val;
    }

    int popRear(){
        if(rear == -1) {
            return -1;
        }

        int val = arr[rear];
        arr[rear] = -1;

        if(front == rear) {
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1;
        }
        else {
            rear--;
        }

        return val;
    }

    int getFront(){
        if(isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear(){
        if(isEmpty())
            return -1;

        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1) {
            return true;
        }
        return false;
    }

    bool isFull(){
        if((front == 0 && rear == size-1) || rear+1 == front ) {
            return true;
        }
        return false;
    }
};