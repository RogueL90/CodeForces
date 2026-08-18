#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<bool> track(26, false);
        for(int i =0; i<n; i++){
            string x;
            cin>>x;
            track[x[0]-'a']=true;
        }
        bool valid = true;
        for(int i = 0; i<m; i++){
            string x;
            cin>>x;
            for(char b : x){
                if(!track[b-'A'])valid = false;
            }
        }
        if(valid){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }

    return 0;
}