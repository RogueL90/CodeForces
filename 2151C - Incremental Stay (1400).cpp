#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> a(2*n, 0);
        for(int i =0; i<2*n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        ll cumul = 0;
        vector<ll> p = a;
        p[0] =0;
        for(int i = 1; i<2*n; i++){
            if(i&1) p[i] = p[i-1]+a[i]-a[i-1];
            else p[i]= p[i-1];
        }
        cout<<p[2*n-1]<<" ";
        for(int i = 1; i<n; i++){
            cumul+=a[2*n-i]-a[i-1];
            ll val = p[2*n-1-i]-p[i];
            if(i&1){
                val=val*-1+a[2*n-i-1]-a[i];
            }
            cout<<val+cumul<<" ";
        }
        cout<<'\n';
    }

    return 0;
}