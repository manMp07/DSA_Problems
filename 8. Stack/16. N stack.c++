#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Que.- Design a data structure to implement 'N' stacks using a single array of size 'S'

class NStack0 {
    // Note : This approach gives wrong answer in testcases.
    public:
    int N, S;
    int *top; //top[]
    int **stack; //stack[][]
    
    NStack0 (int N, int S){ // S = size of each array

        //create top[N] = -1.
        this -> N = N;
        top = new int[N];

        for(int i = 0; i < N; i++) {
            top[i] = -1;
        }
        
        // create stack[N][S]
        this -> S = S;
        stack = new int*[N];
        for(int i = 0; i < N; i++) {
            stack[i] = new int[S];
        }
    }

    bool push(int x, int m){ // push x in Mth stack
        m = m - 1;
        if(S - top[m] > 1) {
            top[m]++;
            stack[m][top[m]] = x;
            return true;
        }
        return false;
    }

    int pop(int m){
        m = m - 1;
        if(top[m] >= 0) {
            int num = stack[m][top[m]];
            top[m]--;
            return num;
        }
        return -1;
    }
};

class NStack {
    public:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialize top
        for(int i = 0; i < n; i++) { // this can be done by memset
            top[i] = -1;
        }
        //memset(top, -1, n)

        // initialize next
        for(int i = 0; i < s; i++) { // this can be done by memset
            next[i] = i+1;
        }
        //update last index to -1
        next[s-1] = -1;

        // initialize freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and
    // false otherwise.
    bool push(int x, int m) {
        //check for overflow
        if(freespot == -1) {
            return false;
        }

        //find index
        int index = freespot;
        
        //insert element into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
       
        //update next;
        next[index] = top[m-1];
        
        //update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise 
    // returns the popped element.
    int pop(int m) {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};