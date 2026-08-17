#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==b||b==c||c==a){
            cout<<0<<'\n';
            continue;
        }
        vector<int> abc={a, b, c};
        sort(abc.begin(), abc.end());
        cout<<min(abc[1]-abc[0], abc[2]-abc[1])<<'\n';
    }

    return 0;
}