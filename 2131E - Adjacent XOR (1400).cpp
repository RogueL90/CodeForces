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
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            a[i]= x;
        }
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            b[i] =x;
        }
        if(a[n-1]!=b[n-1]){
            cout<<"NO"<<'\n';
            continue;
        }
        bool ans = true;
        vector<int> c = a;
        for(int i = n-2; i>=0; i--){
            if(a[i]==b[i])continue;
            c[i]=a[i+1]^a[i];
            if(c[i]!=b[i]){
                c[i] = a[i]^c[i+1];
                if(c[i]!=b[i]){
                    ans = false;
                    break;
                }
            }
        }
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}