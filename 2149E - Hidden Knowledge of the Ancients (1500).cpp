#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k, l, r;
        cin>>n>>k>>l>>r;
        vector<int> a(n);
        for(int& x:a)cin>>x;
        unordered_map<int, int> xm;
        unordered_map<int, int> ym;
        xm.reserve(2 * n);
        ym.reserve(2 * n);      
        int i = 0;
        int x = 0;
        int y = 0;
        long long ans = 0;
        while(i<n){
            if(x<n&&(int)xm.size()<k){
                xm[a[x++]]++;
                continue;
            }else if(y<n&&((int)ym.size()<k||ym.contains(a[y]) )){
                ym[a[y++]]++;
                continue;
            }else{
                if((int)ym.size()==k && (int)xm.size()==k)
                ans+=max(0, min(i+r-1, y-1)-max(i+l-1, x-1)+1);
                ym[a[i]]--;
                xm[a[i]]--;
                if(!ym[a[i]])ym.erase(a[i]);
                if(!xm[a[i]])xm.erase(a[i]);
                i++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}