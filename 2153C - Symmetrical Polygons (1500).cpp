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
        sort(a.begin(), a.end());
        ll ans = 0;
        vector<ll> vals;
        int interactions = 0;
        int c = 0;
        ll prev = 0;
        for(int i = 0; i<n; i++){
            if(prev==a[i]){
                c++;
            }
            else{
                int cnt = c>>1<<1;
                interactions+=cnt;
                ans+=prev*cnt;
                if(c&1){
                    vals.push_back(prev);
                }
                prev = a[i];
                c=1;
            }
        }
        int cnt = c>>1<<1;
                interactions+=cnt;
                ans+=prev*cnt;
                if(c&1){
                    vals.push_back(prev);
                }
        sort(vals.begin(), vals.end());
        if(vals.size()==1){
            if(vals[0]<ans){
                ans+=vals[0];
                interactions++;
            }
        } else 
        for(int i = (int)vals.size()-1; i>0; i--){
            if(vals[i]-vals[i-1]<ans){
                interactions+=2;
                ans+=vals[i]+vals[i-1];
                break;
            }
            if(i==1&&vals[0]<ans){
                interactions++;
                ans+=vals[0];
            }
        }
        if(interactions<3)cout<<0<<'\n';
        else cout<<ans<<'\n';
    }

    return 0;
}