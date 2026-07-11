#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int tc = 0;
        bool done = false;
        for(int i =0; i<k; i++){
            int x;
            cin>>x;
            if(x==2)tc++;
            if(tc==2 || x>2){
                done = true;
            }
        }
        if(!done)
        cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }

    return 0;
}