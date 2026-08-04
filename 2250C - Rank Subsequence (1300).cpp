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
        vector<vector<int>> a(n+1, vector<int>(4));
        for(int i =1; i<=n; i++){
            int l, r, u, v;
            cin>>l>>r>>u>>v;
            a[i] = {l, r, u, v};
        }
        int mid = n;
        while(mid){
            bool done = true;
            int val =1;
        for(int i =1; i<=mid; i++){
                if(val>n){
                    done = false;
                    break;
                }
                bool valid = false;
                if((i<a[val][0]||i>a[val][1])&&(i<mid-a[val][3]+1||i>mid-a[val][2]+1)) valid = true;
                if(!valid){
                    if(val>=n){
                        done = false;
                        break;
                    }
                    i--;
                }
                val++;
            }
           if(done)break;
           mid--;
        }
        cout<<mid<<'\n';
    }

    return 0;
}