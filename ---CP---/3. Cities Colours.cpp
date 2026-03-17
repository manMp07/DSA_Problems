// Problem : https://www.codechef.com/problems/CITCOL

void solve(){
    int n; cin >> n;
    int k; cin >> k;
    
    vi w(n), c(n);
    iarr(w,n);
    iarr(c,n);
    
    /*** DP LOGIC ***
        type0 : myColor != cityColor
        type1 : myColor == cityColor
        
        dp[i][1] = max of { dp[i+1][0] + w[i],
                            dp[j][1] - sumOfW(i+1, j-1) + w[i] }
                ;here j is the next occurence of same color
        
        dp[i][0] = max of { dp[i+1][0] - w[i],
                            dp[i][1] - k }
                            
        final Answer = dp[0][1]
    */
    
    vector<int> nextSame(n);
    unordered_map<int,int> mp;
    rfl(i,n-1,0){
        if(mp.find(c[i]) == mp.end())
            nextSame[i] = -1;
        else
            nextSame[i] = mp[c[i]];
        mp[c[i]] = i;
    }
    vector<ll> prefW(n); prefW[0] = w[0];
    fl(i,1,n) prefW[i] = prefW[i-1] + w[i];
    
    vector<vector<ll>> dp(n, vector<ll>(2, -1e9));
    dp[n-1][1] = w[n-1];
    dp[n-1][0] = max(-w[n-1], w[n-1]-k);
    
    rfl(i, n-2, 0){
        rfl(type, 1, 0){
            ll ans;
            if(type == 0){
                ans = max(dp[i+1][0] - w[i], dp[i][1] - k);
            }
            else{
                ll midSum, j = -1;
                if(nextSame[i] != -1){
                    j = nextSame[i];
                    midSum = prefW[j-1] - prefW[i];
                }
                ans = w[i] + dp[i+1][0];
                if(j != -1)
                    ans = max(ans, w[i] + dp[j][1] - midSum);
            }
            dp[i][type] = ans;
        }
    }
    
    cout << dp[0][1] << endl;
}
