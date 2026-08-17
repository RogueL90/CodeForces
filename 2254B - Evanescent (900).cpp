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
        char curr = s[0];
        int currT = 0;
        vector<int> cnt;
        vector<char> a;
        for(int i = 0;i<n; i++){
            if(s[i]!=curr){
                a.push_back(curr);
                cnt.push_back(currT);
                curr = s[i];
                currT = 0;
            }
            currT++;
        } 
        a.push_back(curr);
        cnt.push_back(currT);
        int ans = cnt.size();
        bool doable = false;
        for(int i = 1; i<(int)cnt.size()-1; i++){
            if(cnt[i]==1){
                doable = true;
                if(a[i-1]==a[i+1]){
                    ans--;
                    break;
                }
                
            }
        }
        if(doable)ans--;
        cout<<ans<<'\n';
    }

    return 0;
}