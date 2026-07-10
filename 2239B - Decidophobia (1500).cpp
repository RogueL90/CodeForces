#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        int l = n-d;
        int r = l;
        long long sum = a[r];
        for(int i = 0; i<2*d; i++){
            r=(r+1)%n;
            sum+=a[r];
        }
        long long ans = 0;
        long long dd = 2*d;
        for(int i =0; i<n; i++){
            sum-=a[i];
            long long val= dd*a[i]-sum;
            if(val>0)ans+=val;
            sum+=a[i];
            r=(r+1)%n;
            sum+=a[r];
            sum-=a[l];
            l =(l+1)%n;
        }
        cout<<ans<<'\n';
    }

    return 0;
}