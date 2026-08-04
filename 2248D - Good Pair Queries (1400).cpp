#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        string s, t;
        cin>>s>>t;
        vector<vector<int>> pre(n+1, vector<int>(4, 0));
        for(int i = 1; i<=n; i++){
            if(s[i-1]=='0'){
                if(t[i-1]=='1') pre[i][0]++;
                else pre[i][2]++;
            }else{
                if(t[i-1]=='0') pre[i][1]++;
                else pre[i][3]++;
            }
            for(int k = 0; k<4; k++){
                pre[i][k]+=pre[i-1][k];
            }
        }
        for(int i =0; i<q; i++){
            int l, r;
            cin>>l>>r;
            int one = abs(pre[r][0]-pre[l-1][0]-(pre[r][1]-pre[l-1][1]));
            int two = pre[r][2]-pre[l-1][2]+pre[r][3]-pre[l-1][3];
            if(one<=two){
                cout<<"YES"<<'\n';
            }else cout<<"NO"<<'\n';
        }
        
    }

    return 0;
}