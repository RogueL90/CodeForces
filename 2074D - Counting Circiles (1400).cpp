#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, v;
        cin>>n>>v;
        vector<ll> centers(n, 0);
        vector<ll> rad(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            centers[i] =x;
        }
        for(int i =0 ; i<n; i++){
            int x;
            cin>>x;
            rad[i] = x;
        }
        unordered_map<ll, int> m;
        for(int i =0; i<n; i++){
            for(ll k = centers[i]-rad[i]; k<=centers[i]+rad[i]; k++){
                m[k]=max(m[k], (int)sqrt(rad[i]*rad[i]-(k-centers[i])*(k-centers[i])));
            }
        }
        long long ans =0;
        for(auto [key, val] : m){
            ans+=2*val+1;
        }
        cout<<ans<<'\n';
    }

    return 0;
}