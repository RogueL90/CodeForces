#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n-2<k){
            cout<<-1<<'\n';
            continue;
        }
        string ans = "";
        for(int i =0; i<k/2+1; i++){
            ans.push_back('0');
        }
        for(int i =0; i<(k+1)/2+1; i++){
            ans.push_back('1');
        }
        bool flag = false;
        while(ans.size()<n){
            if(flag){
                ans.push_back('1');
            }else{
                ans.push_back('0');
            }
            flag = !flag;
        }
        cout<<ans<<'\n';
    }

    return 0;
}