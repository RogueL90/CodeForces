
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<bool> a(n+1, false);
        for(int i = 1;i<=n;i++){
            int x;
            cin>>x;
            if(x){
                a[i] = true;
            }
        }
        vector<int> pre0(n+1,0);
        vector<int> pre1(n+1, 0);
        for(int i = 1; i<=n; i++){
            pre0[i]+=pre0[i-1]+(!a[i]&&!a[i-1]?1:0);
            pre1[i]+=pre1[i-1]+(a[i]&&a[i-1]?1:0);
        }
        vector<int> p0(n+1,0);
        vector<int> p1(n+1, 0);
        for(int i = 1; i<=n; i++){
            p0[i]+=p0[i-1]+1-a[i];
            p1[i]+=p1[i-1]+a[i];
        }
        for(int i = 0; i<q; i++){
            int l, r;
            cin >>l>>r;
            if((p1[r]-p1[l-1])%3!=0 || (p0[r]-p0[l-1])%3!=0){
                cout << -1<<'\n';
                continue;
            }
            cout<<(r-l+1)/3+(pre0[l]==pre0[r] && pre1[l]==pre1[r])<<'\n';
        }
    }

    return 0;
}