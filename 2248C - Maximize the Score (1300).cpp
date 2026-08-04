#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> dp(2*n+1, 0);
        vector<int> a(2*n, 0);
        vector<int> done(n+1, 0);
        for(int& x: a) cin>>x;
        for(int i = 2*n-1; i>=0; i--){
            int curr = a[i];
            if(done[curr]){
                ll val = done[curr]-i+1;
                dp[i] = max(dp[i+1]+1, val*val+dp[done[curr]+1]);
            }else{
                dp[i]=dp[i+1]+1;
                done[curr] = i;
            }
        }
        cout<<dp[0]<<'\n';
    }

    return 0;
}