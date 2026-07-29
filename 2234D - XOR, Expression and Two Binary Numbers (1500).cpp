#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string l, r;
        cin>>l>>r;
        ll x = (pow(2, k)+(k&1?1:2))/3;
        vector<ll> a(3, 0);
        for(int i =0; i<n; i++){
            if(l[i]=='1')a[0]++;
            if(r[i]=='1')a[1]++;
            if(l[i]-'0'+r[i]-'0'==1)a[2]++;
        }
        ll ans = x*a[0]*(n-a[0])+x*a[1]*(n-a[1])+(x-(k&1?0:1))*a[2]*(n-a[2]);
        cout<<ans<<'\n';

    }

    return 0;
}