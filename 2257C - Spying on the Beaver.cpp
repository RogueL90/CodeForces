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
        vector<int> p(n-1);
        for(int& x:p)cin>>x;
        int m;
        cin>>m;
        vector<bool> track(n+1, false);
        for(int i = 0; i<m; i++){
            int x;
            cin>>x;
            track[x]= true;
        }
        int special = -1;
        if(!track[1]){
            for(int i = 2; i<=n; i++){
                if(track[i]){
                    special = i;
                    int next = p[i-2];
                    while(next!=1){
                        if(track[next])special = next;
                        next = p[next-2];
                    }
                    break;
                }
            }
        }
        int amt= m;
        if(track[1])amt--;
        if(special!=-1)amt--;
        if(special){
            cout<<amt<<" ";
        }
        for(int i = 2; i<=n; i++){
            if(track[i]&&i!=special)cout<<i<<" ";
        }
        cout<<'\n';
    }

    return 0;
}