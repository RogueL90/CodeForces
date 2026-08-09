#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ll s, m;
        cin>>s>>m;
        vector<ll> vals = {};
        bool invalid = false;
        ll v=0;
        for(int i =0; m>0; i++){
            if(m&1){
                if(vals.empty()){
                    v = pow(2, i);
                    if(s%v!=0){
                        invalid =true;
                        break;
                    }
                }
                vals.push_back((pow(2, i)));
            }
            m>>=1;
        }
        if(invalid){
            cout<<-1<<'\n';
            continue;
        }
        ll l = 0;
        ll r= s/v;
        ll ans = -1;
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll currS = s;
            for(int i = vals.size()-1; i>=0; i--){
                ll amt = min(mid, currS/vals[i]);
                currS-=amt*vals[i];
            }
            if(currS ==0){
                ans = mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';

    }

    return 0;
}