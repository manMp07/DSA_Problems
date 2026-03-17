#include <bits/stdc++.h>
using namespace std;

/****************************************************/
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define MAN cout.tie(NULL)
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
#define print(x) cout << x << endl;
#define newl cout << endl;
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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void iarr(vi& a, int n){
    fl(i,0,n)
        cin >> a[i];
}
/*********************************************************/

void solve(){
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vll arr(n);
    arr[0] = x;
    fl(i,1,n)
        arr[i] = (a * arr[i-1] + b) % c;

    ll ans = 0;

    deque<ll> dq;
    
    for(int i = 0; i < k; i++){
        while(!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();

        dq.push_back(i);
    }

    ans = arr[dq.front()];

    for(int i = k; i < n; i++){
        while(!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();

        dq.push_back(i);

        if(dq.front() <= i-k)
            dq.pop_front();

        ans = ans ^ arr[dq.front()];
    }

    print(ans);
}

int main() {
    Code By MAN;
    solve();
    
    return 0;
}