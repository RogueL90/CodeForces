#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        vector<int> track(n+1, 0);
        int newV = a[0];
        int cnt = 1;
        int tu = 1;
        for(int i =1; i<n; i++){
            if(a[i]!=newV){
                track[cnt]++;
                newV = a[i];
                tu++;
                cnt = 1;
            }else{
                cnt++;
            }
        }
        track[cnt]++;
        int ans = 0;
        int cn = n;
        for(int i = 1; i<=n; i++){
            if(!track[i])continue;
            int tn = cn-(i-1)*tu;
            if(k-tn>=0 && (k-tn)%tu==0)ans++;
            cn-=track[i]*i;
            tu-=track[i];
            if(cn==0)break;
        }
        cout<<ans<<'\n';
    }

    return 0;
}