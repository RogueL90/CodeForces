#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int ans = 0;
        int minVal = INT_MAX;
        for(int i = 0; i<n; i++){
            int x;
            cin>> x;
            if(x<minVal){
                minVal = x;
            }
            ans+=minVal;
        }
        cout << ans << '\n';
    }

    return 0;
}