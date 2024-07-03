#include <bits/stdc++.h>
using namespace std;

class SegTree {
    vector<int> seg;
    
    public :
    SegTree(int n){
        seg.resize(4*n+1);
    }
    
    void print(){
        for(int i = 0; i < seg.size(); i++)
            cout << seg[i] << " ";
        cout << endl;
    }
    
    void build(int i, int lo, int hi, int a[]){
        if(lo == hi){
            seg[i] = a[lo];
            return;
        }
        
        int mid = (lo + hi) >> 1;
        
        build(2*i + 1, lo, mid, a);
        build(2*i + 2, mid+1, hi, a);
        
        seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
    }
    
    int query(int i, int lo, int hi, int l, int r){
        // no overlap : (lo, hi) (l, r) or (l, r) (lo, hi)
        if(hi < l || r < lo)
            return INT_MAX;
        
        // complete overlap
        if(l <= lo && hi <= r)
            return seg[i];
            
        // partial overlap
        int mid = (lo + hi) >> 1;
        int left = query(2*i+1, lo, mid, l, r);
        int right = query(2*i+2, mid+1, hi, l, r);
        
        return min(left, right);
    }
    
    void update(int i, int lo, int hi, int idx, int val){
        if(lo == hi){
            cout << "Base" << endl;
            seg[i] = val;
            return;
        }
        
        int mid = (lo + hi) >> 1;
        
        if(idx <= mid)
            update(2*i + 1, lo, mid, idx, val);
        else
            update(2*i + 2, mid+1, hi, idx, val);
            
        seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
    }
};


int main() {
    int n;
    cin >> n;
    int q;
    cin >> q;

    int a[n];    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    SegTree sg(n);
    
    sg.build(0, 0, n-1, a);
    sg.print();
    
    while(q--){
        int type;
        cin >> type;
        
        if(type == 1){
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n-1, l, r) << endl;
        }
        
        else{
            int idx, val;
            cin >> idx >> val;
            a[idx] = val;
            
            sg.update(0, 0, n-1, idx, val);
            sg.print();
        }
    }
}

/* Test Case : 
6 3
1 3 2 0 4 5
1 0 2 ---> Ans = 1
2 0 6 ---> Update
1 0 2 ---> Ans = 2
*/