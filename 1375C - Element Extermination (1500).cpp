#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i =0;i<n; i++){
            int x;
            cin >> x;
            a[i] = x;
        }
        int miv = a[n-1];
        int mav = miv;
        for(int i = n-2; i>0; i--){
            if(a[i] <mav)continue;
            mav = a[i];
        }
        if(a[0]<miv){
            cout << "YES" <<'\n';
        }else{
            cout << "NO" <<'\n';
        }
    }

    return 0;
}