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
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        if(n%2==1){
            cout<<"NO"<<'\n';
            continue;
        }
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        for(int i =0; i<n; i++){
            if(i&1){
                max1 = max(max1, a[i]);
            }else min1 = min(min1, a[i]);
        }
        int val = false;
        unordered_set<int> m;
        for(int vals : a) m.insert(vals);
        for(int i =max1+1; i<min1; i++){
            if(!m.contains(i)){
                val = true;
                break;
            }
        }
        if(val)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}