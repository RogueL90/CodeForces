#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >>k;
        vector<int> track(n+1, 0);
        vector<int> pre(n+1, 0);
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            track[x]++;
        }
        for(int i =1; i<=n; i++){
            pre[i] = pre[i-1]+track[i];
        }
        int ans =0;
        int comp = n-k;
        for(int g = 1; g<=n; g++){
            int good = n-pre[min(4*g-1, n)] + track[g];
            if(2*g<=n)good+=track[2*g];
            if(3*g<=n)good+=track[3*g];
            if(good >=comp)ans = g;
        }
        cout << ans<<'\n';
    }

    return 0;
}