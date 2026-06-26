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
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            a[i] = x;
        }
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        pre[0] = a[0];
        suf[n-1] = a[n-1];
        for(int i =1; i<n;i++){
            pre[i] = min(pre[i-1], a[i]);
            suf[n-i-1] = max(suf[n-i], a[n-1-i]);
        }
        bool possible = true;
        if(a[0] == n){
            cout << "No" << '\n';
            continue;
        }
        for(int i =1; i<n; i++){
            if(pre[i-1]>suf[i]){
                possible = false;
                break;
            }
        }
        cout << (possible?"Yes":"No")<<'\n';
    }

    return 0;
}