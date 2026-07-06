#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string aa, bb;
        cin>> aa>>bb;
        int n = aa.size();
        int m = bb.size();
        vector<int> a(n, 0);
        vector<int> b(m, 0);
        for(int i =0;i<n; i++){
            a[i] = aa[i]-'0';
        }
        for(int i =0;i<m; i++){
            b[i] = bb[i]-'0';
        }
        vector<int> pa(n+1, 0);
        vector<int> pb(m+1, 0);
        for(int i =n-1; i>=0; i--){
            pa[i] = (pa[i+1]+a[i])%10;
        }
        for(int i =m-1; i>=0; i--){
            pb[i] = (pb[i+1]+b[i])%10;
        }
        int i0 = 0;
        int i1 = 0;
        int ans = 0;
        int prev = 0;
        while(i0<n && i1<m){
            int ap = ans;
            int targ = (b[i1]+prev)%10;
            int c = 0;
            int t0 = i0;
            while(t0<n){
                c=(c+a[t0])%10;
                t0++;
                if(c==targ){
                    ans++;
                    break;
                }
            }
            if(ap!=ans){
                prev = 0;
                i0 = t0;
            }else{
                prev +=b[i1];
            }
            i1++;
        }
        if(pa[i0] ==0 && pb[i1]==0){
            cout << ans<<'\n';
        }else{
            cout <<-1<<'\n';
        }
    }

    return 0;
}