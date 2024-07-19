// Codechef Starters 143
// Que.- https://www.codechef.com/problems/MAXMINLEN

#include <bits/stdc++.h>
using namespace std;

#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Asquare cout.tie(NULL)
#define ll long long
#define ff first
#define ss second
#define fl(i,s,n) for(ll i = s; i < n; i++)
#define rfl(i,n,s) for(ll i = n; i >= s; i--)
#define pb(x) push_back(x)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define srt(a) sort(a.begin(), a.end())
#define prtArr(a,s,n) fl(i,s,n) cout << a[i] << " ";

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef pair<int, int> pii;
typedef set<int> si;

bool isPrime(ll n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false; ll i = 5;
    while(i*i <= n){ if(n%i == 0 || n % (i+2) == 0) return false; i += 6; }
    return true;
}

ll solve(int a[], int n){
    sort(a, a+n);
    
    vll pre(n); pre[0] = 1;
    vll suff(n); suff[n-1] = 1;
    
    fl(i,1,n){
        if(a[i] - a[i-1] == 1)
            pre[i] = pre[i-1] + 1;
        else
            pre[i] = 1;
    }
    
    rfl(i,n-2,0){
        if(a[i+1] - a[i] == 1)
            suff[i] = suff[i+1] + 1;
        else
            suff[i] = 1;
    }
    
    ll ans = 0;
    fl(i, 0, n-1){
        if(a[i+1] - a[i] == 2)
            ans += (pre[i] * suff[i+1]);
            
        else if(i+2 < n && a[i+2] - a[i] == 2)
            ans += (pre[i] * suff[i+2]);
    }
    
    return ans;
}

int main() {
    Code By Asquare;
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int a[n];
        fl(i,0,n)
            cin >> a[i];
            
        cout << solve(a, n) << endl;
    }
    
    return 0;
}