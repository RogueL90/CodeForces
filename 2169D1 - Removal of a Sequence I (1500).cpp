#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll x, y, k;
        cin>>x>>y>>k;
        ll l = 0;
        ll r = 1000000000000;
        ll ans = -1;
        while(l<=r){
            ll d = l+(r-l)/2;
            ll org = d;
            bool valid = true;
            for(ll i = 0; i<x; i++){
                if(d%y==0){
                    valid = false;
                }
                d-=d/y-(d%y==0?1:0);
            }
            if(d <k||(!valid && d==k)){
                l = org+1;
            }else if(d>k ){
                r = org-1;
            }else{
                ans = org;
                break;
            }

        }
        cout<<ans<<'\n';
    }
    

    return 0;
}