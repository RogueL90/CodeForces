#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll x,y,k;
        cin>>x>>y>>k;
        ll ans = 0;
        while(x*2<=y && k){
            ans+=y%x;
            y++;
            x++;
            k--;
        }
        ans+=k*(y-x);
        cout<<ans<<'\n';
    }

    return 0;
}