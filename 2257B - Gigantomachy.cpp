#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<ll> a(n, 0);
        vector<ll> b(m,0);
        for(ll& x: a)cin>>x;
        for(ll& x:b)cin>>x;
        ll aCap = 0;
        ll bCap = 0;
        for(int i = 0; i<n-1; i++){
            aCap+=a[i]-a[i+1]+1;
        }
        for(int i = 0; i<m-1; i++){
            bCap+=b[i]-b[i+1]+1;
        }
        aCap+=a[n-1];
        bCap+=b[m-1];
        if(aCap<bCap){
            cout<<2<<'\n';
        }else{
            cout<<1<<'\n';
        }
    }

    return 0;
}