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
        vector<vector<int>> aPre(n, vector<int>(2));
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            if(i==0){
                aPre[i][0]=aPre[i][1]=x;
            }else if(x<=aPre[i-1][1]&&x>=aPre[i-1][0]){
                aPre[i][0] = aPre[i-1][0];
                aPre[i][1] = aPre[i-1][1];
            }else{
                aPre[i][0] = min(aPre[i-1][0], x);
                aPre[i][1] = max(aPre[i-1][1], x);
            }
        }
        vector<vector<int>> bPre(n, vector<int>(2));
        vector<int> b(n);
        for(int& x: b)cin>>x;
        for(int i = n-1; i>=0; i--){
            int x = b[i];
            if(i==n-1){
                bPre[i][0]=bPre[i][1]=x;
            }else if(x<=bPre[i+1][1]&&x>=bPre[i+1][0]){
                bPre[i][0] = bPre[i+1][0];
                bPre[i][1] = bPre[i+1][1];
            }else{
                bPre[i][0] = min(bPre[i+1][0], x);
                bPre[i][1] = max(bPre[i+1][1], x);
            }
        }
        ll ans = 0;
        vector<int> l(2*n+1, 2*n+1);
        for(int i = 0; i<n; i++){
            int low = min(aPre[i][0], bPre[i][0]);
            int high = max(aPre[i][1], bPre[i][1]);
            l[low]=min(l[low], high);
        }
        ll prev = 2*n+1;
        for(int i = prev-1; i>=1; i--){
            prev = min((ll)l[i], prev);
            ans+=(2*n+1-prev);
        }
        cout<<ans<<'\n';


    }

    return 0;
}