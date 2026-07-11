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
        vector<int> a(n+1, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[x]++;
        }
        vector<int> ans(n+1, 0);
        int c = 0;
        while(a[c])c++;
        for(int i = c;i>=0; i--){
            if(a[i]>0) ans[a[i]-1]--;
            ans[n-i]++;
        }
        ll curr = 0;
        for(int i = n; i>=0; i--){
            curr+=ans[i];
            ans[i]=curr;
        } 
        for(int i =0; i<=n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}