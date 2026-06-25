#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int a, b, c, d;
        cin >> a >>b>>c>>d;
        int ans;
        if(a < min(c, d) && b < min(c, d)){
            ans=abs(b-a);
            b = max(a, b);
            ans+=min(c, d)-b;
            ans+=abs(c-d);
        }else{
            ans = c-a+d-b;
        }
        cout << ans << '\n';
    }

    return 0;
}