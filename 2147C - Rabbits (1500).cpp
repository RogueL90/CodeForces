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
        string s;
        cin>>s;
        s.push_back('0');
        bool valid = true;
        vector<int> dp(n+1, 0);
        dp[n]=1;
        for(int i = n-1; i>=0; i--){
            if(s[i]=='1'){
                dp[i]=-1;
                if(i<n-2 && dp[i+1]==-1&&dp[i+2]==0){
                    valid = false;
                    break;
                }
            }else{
                if(s[i+1]=='0'){
                    dp[i]=1;
                    continue;
                }
                int status = 0; 
                if(i<n-2){
                    if(dp[i+2]==1)status = 1;
                    else if(dp[i+2]==0)status = 2;
                }
                dp[i]=status;
            }
        }
        if((int)dp.size()>=2 && dp[0]==-1&& dp[1]==0)valid = false;
        if(valid)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}