#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll s, q;
        cin>>s>>q;
        ll sq = sqrt(s);
        vector<ll> vals;
        for(int i =1; i<=sq; i++){
            if(s%i==0){
                vals.push_back(i);
            }
        }
        for(int i = vals.size()-1; i>=0; i--){
            vals.push_back(s/vals[i]);
        }
        ll vs = vals.size();
        vector<ll> pre(vs+1);
        pre[1] = s;
        for(int i =2; i<=vs; i++){
            pre[i]=pre[i-1]+(vals[i-1]-vals[i-2])*(s/vals[i-1]);
        }
        for(int i =0; i<q; i++){
            ll x, y;
            cin>>x>>y;
            ll full = -1;
            ll l = 0;
            ll r = vs-1;
            while(l<=r){
                ll mid = l+(r-l)/2;
                ll height = s/vals[mid];
                if(height>=y){
                    l = mid+1;
                    full = mid;
                }else{
                    r =mid-1;
                }
            }
            l = 0; 
            r = vs -1;
            ll dist = -1;
            while(l<=r){
                ll mid = l+(r-l)/2;
                if(vals[mid]<=x){
                    dist = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            ll ans = 0;
            if(full!=-1)ans+=y*min(x, vals[full]);
            if(dist!=-1&& x>vals[full])ans+=pre[dist+1]-pre[full+1];
            if(dist!=vs-1&& dist != -1 && vals[dist]<x && x>vals[full])ans+=(x-vals[dist])*(s/vals[dist+1]);
            cout<<ans<<'\n';

        }
    }

    return 0;
}