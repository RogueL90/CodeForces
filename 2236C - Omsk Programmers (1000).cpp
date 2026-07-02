#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int x, a, b;
        cin >> a>> b>> x;
        int cnt = 0;
        while(a!=b){
            int big = a> b ? a : b;
            int small = big == a ? b : a;
            if(abs(big/x-small)<big-small || abs(big/x-small/x)<big-small-1){
                cnt++;
                if(big == a){
                    a/=x;
                }else{
                    b/=x;
                }
            }else{
                break;
            }
        }
        cout << cnt+abs(a-b) << '\n';
    }

    return 0;
}