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
        int first = 0;
        int last = n-1;
        int cntZ=0;
        int fl=0;
        for(int i = 0; i<n;i++){
            int x;
            cin>>x;
            if(x==0){
                cntZ++;
                if(i==first||i==last)fl++;
            }
        }
        if(cntZ<2)cout<<-1<<'\n';
        else cout<<2-fl<<'\n';
    }

    return 0;
}