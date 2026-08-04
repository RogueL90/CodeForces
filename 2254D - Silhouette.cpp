#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
using ll = long long;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> b(n);
        for(ll& x:b)cin>>x;
        vector<int> bs(n);
        for(int i =0; i<n; i++)bs[i] =i;
        sort(bs.begin(), bs.end(), [&](int a1, int b1){return b[a1]<b[b1];}); 
        vector<ll> vals;
        vals.reserve(n);
        ll cv = b[bs[0]];
        if(cv!=0){
            cout<<-1<<'\n';
            continue;
        }
        ll currS = 0;
        bool invalid = false;
        for(int i =0; i<n; i++){
            if(b[bs[i]]==cv){
                currS++;
            }else{
                ll curr = b[bs[i]];
                if((curr-cv)%currS!=0){
                    invalid = true;
                    break;
                }
                ll newVal = (curr-cv)/currS;
                if(!vals.empty()&&newVal<=vals.back()){
                    invalid=true;
                    break;
                }
                for(int k=0; k<currS; k++)vals.push_back(newVal);
                cv = curr;
                currS=1;
            }
        }
        if(invalid){
            cout<<-1<<'\n';
            continue;
        }
        int s = vals.size();
        ll newVal = !vals.empty()?vals.back()+1:1;
        for(int i =0; i<((int)bs.size()-s); i++){
            vals.push_back(newVal);
        }
        vector<ll> ans(n);
        for(int i =0; i<n; i++){
            ans[bs[i]]=vals[i];
        }
        for(ll x : ans){
            cout<<x<<" ";
        }
        cout<<'\n';

    }
    return 0;
}