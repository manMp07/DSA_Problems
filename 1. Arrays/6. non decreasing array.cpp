#include<bits/stdc++.h>
using namespace std;

// You have been  given an integer array arr[] of size N. Write a solution to check if it could become non-decreasing(increasing) array by modifying at most 1 element.

bool isPossible(int arr[], int n) {
    int NotInOrder_Index = -1;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            /* If more than 1 Index is not in non-decreasing
			 order then we can return false.*/
            if(NotInOrder_Index != -1) {
                return false;
            }
            NotInOrder_Index = i;
        }
    }

    /*If Everyone is in Order OR Only First Number
		is not in Order OR Only Last
		number is not in Order.*/
    if(NotInOrder_Index == -1 || NotInOrder_Index == 0 || NotInOrder_Index == n-2) {
        return true;
    }

    /* If we can change arr[notInOrderIndex] to be between arr[notInOrderIndex - 1] and
     arr[notInOrderIndex + 1].*/
    if(arr[NotInOrder_Index - 1] <= arr[NotInOrder_Index + 1]) {
        return true;
    }

    /* If we can change arr[notInOrderIndex + 1]
		to be between arr[notInOrderIndex]
		and arr[notInOrderIndex + 2].*/
    if(arr[NotInOrder_Index] <= arr[NotInOrder_Index + 2]) {
        return true;
    }

    /* If there is no way to make the array
		non-decreasing by modifying at most 1
	    element.*/
    return false;
}

int main() {
    int n; cin >> n;
    int arr[n]; //-41 -40 -22 -14 -14 -1 17 59 -130 92
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(isPossible(arr,n) == true) {
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}