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
        bool valid = true;
        if(s[0]=='0')valid = false;
        for(int i = 1; i<n; i++){
            if(s[i]=='0'&&s[i-1]=='0'){
                valid = false;
                break;
            }
        }
        if(!valid){
            cout<<-1<<'\n';
            continue;
        }
        int curr = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(c=='0'){
                ans= max(ans, abs(curr));
                curr = 0;
            }else if(c=='-'){
                if(curr==0){
                    curr--;
                    ans= max(ans, 1);
                }else if(curr>0){
                    int diff = curr+1;
                    if(diff==3 && !(i>2&&s[i-1]=='+'&&s[i-2]=='+'&&s[i-3]=='-'))diff=2;
                    ans = max(ans, diff);
                    curr=-1;
                }else{
                    if(curr==-1)curr--;
                    else curr++;
                }
            }else{
                if(curr==0){
                    curr++;
                    ans= max(ans, 1);
                }else if(curr<0){
                    int diff = abs(curr-1);
                    if(diff==3 && !(i>2&&s[i-1]=='-'&&s[i-2]=='-'&&s[i-3]=='+'))diff=2;
                    ans = max(ans, diff);
                    curr=1;
                }else{
                    if(curr==1)curr++;
                    else curr--;
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}