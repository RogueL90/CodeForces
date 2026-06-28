#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>> t;
    while(t--){
        int n, k;
        cin >> n>>k;
        k = min(k, n);
        int val=0;
        int bv = 0;
        while(((val<<1)|1)*k<=n){
            bv++;
            val<<=1;
            val|=1;
        }
        int ans = bv*k;
        n-= val*k;
        int cnt = k;
        while(pow(2, bv)<=n){
            ans++;
            n-=pow(2, bv);
            cnt--;
            if(cnt == 0){
                bv++;
                cnt = k;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}