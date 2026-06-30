#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int x;
        cin>>x;
        int digits =0;
        while(x>0){
            x/=10;
            digits++;
        }
        int y = pow(10, digits);
        cout<<y+1<<'\n';
    }

    return 0;
}