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
        vector<int> p(n, 0);
        vector<int> s(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            p[i] = x;
        }
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            s[i] = x;
        }
        bool check = true;
        if(s[0]!=p[n-1]){
            check = false;
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        for(int i =0; i<n-1; i++){
            if(p[i]%p[i+1]!=0){
                check = false;
                break;
            }
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        for(int i = n-1; i>0; i--){
            if(s[i]%s[i-1]!=0){
                check = false;
                break;
            }
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        vector<ll> b(n, 0);
        for(int i =0; i<n; i++){
            b[i] = lcm((ll)p[i], (ll)s[i]);
        }
        if(b[0]!=p[0]|| b[n-1]!=s[n-1]){
            check = false;
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        for(int i =1; i<n; i++){
            if(gcd(b[i], p[i-1])!=p[i]){
                check = false;
                break;
            }
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        for(int i = n-2; i>=0; i--){
            if(gcd(b[i], s[i+1])!=s[i]){
                check = false;
                break;
            }
        }
        if(!check){
            cout<<"NO"<<'\n';
                continue;
        }
        cout<<"YES"<<'\n';
    }

    return 0;
}