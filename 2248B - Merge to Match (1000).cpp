#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        for(int i =0; i<m; i++){
            int x;
            cin>>x;
            b[i] = x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(m*2>n){
            cout<<"NO"<<'\n';
            continue;
        }
        bool valid = true;
        for(int i =0; i<m; i++){
            if(b[i]<a[i]){
                valid = false;
                break;
            }
        }
        for(int i = 0; i<m; i++){
            if(a[n-1-i]<b[m-1-i]){
                valid = false;
                break;
            }
        }
        if(valid){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }

    return 0;
}