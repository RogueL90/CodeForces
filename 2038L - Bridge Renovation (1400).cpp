#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int ans = 0;
    ans+=(n/2)*2;
    if(n&1)ans++;
    if((n-n/2)%3!=0)ans++;
    ans+=(n-n/2)/3;
    cout<<ans;


    return 0;
}