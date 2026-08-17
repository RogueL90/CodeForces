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
        string b;
        cin>>b;
        int cnt0=0;
        int cnt1=0;
        for(char v : b){
            if(v=='0')cnt0++;
            if(v=='1')cnt1++;
        }
        if(abs(cnt0-cnt1)>2){
            cout<<-1<<'\n';
            continue;
        }
        int ex0=0;
        int ex1=0;
        for(int i =1; i<n; i++){
            if(b[i]==b[i-1]){
                if(b[i]=='0')ex0++;
                else ex1++;
            }
        }
        int rem = max(0, abs(ex0-ex1)-1);
        int ans = 2*min(ex1, ex0)+(ex0!=ex1?1:0)+2*rem;
        cout<<ans<<'\n';

    }

    return 0;
}