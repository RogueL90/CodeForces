#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int cnt0a = 0;
        int cnt0b = 0;
        int cnt1b = 0;
        int cnt1a = 0;
        for(int i = 0; i<n; i+=2){
            if(a[i]=='0')cnt0a++;
            if(b[i]=='0')cnt0b++;
        }
        for(int i = 1; i<n; i+=2){
            if(a[i]=='0')cnt1a++;
            if(b[i]=='0')cnt1b++;
        }
        if(cnt0a==cnt0b&&cnt1a==cnt1b){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }

    }

    return 0;
}