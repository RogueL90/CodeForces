#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll MOD = 998244353;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool zero =true;
        int cnt = 0;
        int ans = 0;
        int i =0;
        for(i =0; i<n; i++){
            cnt++;
            if(cnt==3){
                zero = !zero;
                cnt = 1;
            }
            if(zero){
                if(s[i]=='0'||s[i]=='?')continue;
                else break;
            }else if(!zero){
                if(s[i]=='1'||s[i]=='?')continue;
                else break;
            }
        }
        if(i==n)ans++;

        zero = false;
        cnt = 0;
        for(i =0; i<n; i++){
            cnt++;
            if(cnt==3){
                zero = !zero;
                cnt = 1;
            }
            if(zero){
                if(s[i]=='0'||s[i]=='?')continue;
                else break;
            }else if(!zero){
                if(s[i]=='1'||s[i]=='?')continue;
                else break;
            }
        }
        if(i==n)ans++;
        if(s[0]=='0'||s[0]=='?'){
            zero =false;
            cnt = 0;
            for(i =1; i<n; i++){
            cnt++;
            if(cnt==3){
                zero = !zero;
                cnt = 1;
            }
            if(zero){
                if(s[i]=='0'||s[i]=='?')continue;
                else break;
            }else if(!zero){
                if(s[i]=='1'||s[i]=='?')continue;
                else break;
            }
        }
        if(i==n)ans++;
        }
        if(s[0]=='1'||s[0]=='?'){
            zero =true;
            cnt = 0;
            for(i =1; i<n; i++){
            cnt++;
            if(cnt==3){
                zero = !zero;
                cnt = 1;
            }
            if(zero){
                if(s[i]=='0'||s[i]=='?')continue;
                else break;
            }else if(!zero){
                if(s[i]=='1'||s[i]=='?')continue;
                else break;
            }
        }
        if(i==n)ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}