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
        vector<ll> a(n);
        for(ll& x : a)cin>>x;
        int i = n&1?n-2:n-1;
        ll curr=i;
        ll ans = 0;
        for(; i>=0; i--){
            if(!(i&1)){
                ans = max(ans,curr-i+2*(a[curr]-a[i]));
            }else{
                if(2*a[curr]+curr-i<2*a[i])curr = i;
            }
        }
        curr =1;
        for(i = 1; i<n; i++){
            if(!(i&1)){
                ans = max(ans,i-curr+2*(a[curr]-a[i]));
            }else{
                if(2*a[curr]+i-curr<2*a[i])curr = i;
            }
        }
        ans = max(ans, 1LL*(n&1?n-1:n-2));
        for(i = 0; i<n; i++){
            if(i&1)ans-=a[i];
            else ans+=a[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}