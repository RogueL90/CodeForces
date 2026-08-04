#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n-1);
        for(int i =0;i<n-1; i++){
            int x;
            cin>>x;
            a[i]= x;
        }
        
        ll ans = 0;
        cout<<ans<<'\n';

    }

    return 0;
}