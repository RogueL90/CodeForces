#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        vector<bool> s(r+1, false);
        vector<int> a(r+1,0);
        int mask = 1;
        while(mask<=r)mask<<=1;
        mask--;
        for(int i = r; i>=0; i--){
            while(mask-i>r||s[mask-i])mask>>=1;
            a[i] = mask-i;
            s[mask-i]=true;
        }
        cout<<(long long)r*(r+1)<<'\n';
        for(int val : a)cout<<val<<" ";
        cout<<'\n';
    }

    return 0;
}