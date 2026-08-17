#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int a, b,c;
        cin>>a>>b>>c;
        vector<int> e= {a,b,c};
        sort(e.begin(), e.end());
        int ans =min(e[1], e[2]-e[0]);
        cout<< ans<<'\n';
    }

    return 0;
}