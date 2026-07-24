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
        vector<int> b(n,0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            b[i] =x;
        }
        vector<int> track(n+1, 0);
        vector<int> pos(n+1, 0);
        for(int i =0;i<n; i++){
            track[b[i]]=a[i];
        }
        bool end = false;
        bool tol = n&1?true:false;
        for(int i =1; i<=n; i++){
            if(i!= track[track[i]]) {
                cout<<"-1"<<'\n';
                end = true;
                break;
            }
            if(track[i] == i){
                if(tol) tol = false;
                else {
                    cout<<"-1"<<'\n';
                end = true;
                break;
                }
            }
        }
        if(end) continue;
        for(int i = 0; i<n; i++){
            pos[b[i]] = i;
        }
        vector<pair<int, int>> ans;
        ans.reserve(n);
        for(int i = 0; i<n; i++){
            if(a[i]==b[i]&&i!=n/2){
                pos[b[i]]= n/2;
                pos[b[n/2]]=i;
                ans.push_back({n/2+1, i+1});
                int temp = b[i];
                b[i] = b[n/2];
                b[n/2] = temp;
            }
        }
        for(int i =0; i<n/2; i++){
            if(pos[track[b[i]]]==n-1-i)continue;
             int temp = pos[track[b[i]]];
             pos[track[b[i]]]=n-1-i;
             pos[b[n-1-i]]=temp;
             int t1 = b[temp];
             b[temp] = b[n-1-i];
             b[n-1-i] = t1;
             ans.push_back({temp+1, n-i});
        }
        cout<<ans.size()<<'\n';
        for(auto [one, two] : ans){
            cout<<one<<" "<<two<<'\n';
        }

    }

    return 0;
}