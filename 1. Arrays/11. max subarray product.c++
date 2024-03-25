#include<bits/stdc++.h>
using namespace std;

//Que.- Given an array Arr[] that contains N integers (may be positive, negative or zero).
//      Find the product of the maximum product subarray.

/*Brute Force*/
//Time : O(N*N); Find maximum of all subarray products
//Space : O(1)

/*Optimal (Intutive)*/
//Time : O(N); using prefix and suffix product(for more understanding, visit TUF-Striver)
//Space : O(1)

long long maxProduct(vector<int> arr, int n) {
	long long prefix = 1;
	long long suffix = 1;
	long long ans = INT_MIN;
	    
	for(int i = 0; i < n; i++){
	    if(prefix == 0) prefix = 1;
	    if(suffix == 0) suffix = 1;
	        
	    prefix *= arr[i];
	    suffix *= arr[n-i-1];
	        
	    ans = max(ans, max(prefix, suffix));
	}
	return ans;
}

/*Optimal(Modification of Kadane's Algorithm)*/
//Time : O(N); Never Tell this solution to interviewer.
//Space : O(1)

int maxProductSubArray(vector<int> arr, int n) {
    int prod1 = arr[0];
    int prod2 = arr[0];
    int result = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        int temp = max( {arr[i], prod1*arr[i], prod2*arr[i]} );
        prod2 = min( {arr[i], prod1*arr[i], prod2*arr[i]} );
        prod1 = temp;
        
        result = max(result, prod1);
    }
    return result;
}