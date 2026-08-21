#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int a = 0;
        int b = 0;
        if(k-1<n-k)k = n-k+1;
        while(1){
            if(b<n-k&&b+a+max(a, b+1)<=m)b++;
            if(a<k-1&&b+a+max(a+1,b)<=m)a++;
                else break;
        }
        cout<<a+b+1<<'\n';

    }

    return 0;
}
