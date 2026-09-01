#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        unordered_map<int, int> ma;
        for(int& x : a){
            cin>>x;
            if(x%2==0)ma[x/2]++;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int x = 1; x<=m; x++){
            int l = 0;
            int r = n-1;
            int last = n;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(a[mid]>=x){
                    last = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            ans = max(ans, n-last+ma[x]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}