#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<ll> v(n);
        for(ll& x:v)cin>>x;
        vector<vector<ll>>g(n, vector<ll>(m));
        for(auto& g0:g){
            for(auto&g1:g0)cin>>g1;
        }
        vector<pair<ll, int>> all;
        all.reserve(n*m);
        for(int i =0; i<n; i++){
            auto& g0 = g[i];
            for(auto&g1:g0){
                all.push_back({g1, i});
            }
        }
        sort(all.begin(), all.end());
        int minV = m;
        ll minH = INT_MAX;
        for(int lev = 0; lev<n; lev++){
            int budg = m-1;
            int i = all.size()-1;
            ll health = v[lev];
            if(health>=minH)continue;
            else minH = health;
            vector<pair<ll, int>> arr={};
            while(budg>0&&i>=0){
                if(all[i].second<lev){
                    all.pop_back();
                }else{
                    budg--;
                    health-=all[i].first;
                    arr.push_back(all[i]);
                    all.pop_back();
                    if(health<=0)break;
                }
                i--;
            }
            if(health<=0)minV = min(minV, (int)arr.size());
            for(int k = arr.size()-1; k>=0; k--){
                all.push_back(arr[k]);
            }
        }
        cout<<minV<<'\n';
    }

    return 0;
}