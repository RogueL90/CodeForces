#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i = 0;
        int n = s.size();
        for(i=0; i<n; i++){
            if(s[i]=='1')break;
        }
        int l = 0;
        for(l = 0; l<n; l++){
            if(s[l]=='0')break;
        } 
        string st = "";
        for(int k =0; k<n; k++){
            if(k!=l&&k!=i){
                st.push_back(s[k]);
            }
        }
        cout<<st<<'\n';
    }

    return 0;
}