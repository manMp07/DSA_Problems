// Codechef Starters 141
//Que.- https://www.codechef.com/problems/PREPER

#include <bits/stdc++.h>
using namespace std;

int maximumBeauty(int a[], int n){
    vector<int> vec(n-1, 0);
    int originalBeauty = 1;
    
    set<int> st;
    
    for(int i = 0; i < n-1; i++){
        st.insert(a[i+1]);
        
        if(*st.rbegin() == i+1)
            vec[i] = 1;
        
        st.erase(a[i+1]);
        st.insert(a[i]);
        
        if(*st.rbegin() == i+1){
            vec[i] = -1;
            originalBeauty++;
        }
    }
    
    int sum = 0;
    int maxSum = 0;
    
    for(int i = 0; i < n-1; i+=2){
        sum += vec[i];
        maxSum = max(maxSum, sum);
            
        if(sum < 0)
            sum = 0;
    }
    
    sum = 0;
    for(int i = 1; i < n-1; i+=2){
        sum += vec[i];
        maxSum = max(maxSum, sum);
            
        if(sum < 0)
            sum = 0;
    }
    
    return originalBeauty + maxSum;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n; cin >> n;
        int arr[n];
        
        for(int i = 0; i < n; i++)
            cin >> arr[i];
            
        cout << maximumBeauty(arr, n) << endl;
    }
}