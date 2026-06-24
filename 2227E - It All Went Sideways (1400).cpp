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
        long long ans =0;
        int minV = a[n-1];
        int minI = n-1;
        int maxRev = 0;
        for(int i = n-2; i>=0; i--){
            if(a[i] > minV){
                ans+=a[i]-minV;
            }else if(a[i] <minV){
                maxRev = max(maxRev, minI-i-1);
                minV = a[i];    
                minI = i;
            }
        }
        maxRev = max(maxRev, minI);
        cout << ans + maxRev << '\n';
    }

    return 0;
}