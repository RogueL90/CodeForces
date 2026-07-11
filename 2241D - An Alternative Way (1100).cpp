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
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i]=x;
        }
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            b[i]=x;
        }
        long long overflow=0;
        for(int i =0; i<n; i++){
            overflow +=(b[i]-a[i]);
            if(overflow<0) break;
        }
        if(overflow>=0){
            cout << "YES"<<'\n';
        }else{
            cout <<"NO"<<'\n';
        }
    }

    return 0;
}