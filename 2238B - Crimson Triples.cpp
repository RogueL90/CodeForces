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
        long long ans = 0;
        for(int i = 1; i<=n; i++){
            long long vals = n/i;
            ans+=vals*vals;
        }
        cout << ans << '\n';
    }

    return 0;
}