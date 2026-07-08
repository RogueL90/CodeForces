#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        int n = a.size();
        int i = 0;
        int ans = 0;
        while(i<n && a[i]==b[i]){
            ans+=2;
            i++;
        }
        if(i<n && a[i]+1==b[i]){
            int ia = i+1;
            int ib = i+1;
            while(ia<n && a[ia]=='9')ia++;
            while(ib<n && b[ib]=='0')ib++;
            ans+=min(ia, ib)-i;
        }
        cout<<ans<<'\n';
    }

    return 0;
}