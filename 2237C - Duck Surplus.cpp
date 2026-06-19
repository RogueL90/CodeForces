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
        long long mVal =0;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            if(x>= mVal){
                mVal = x;
            }else{
                mVal+=x;
            }
        }
        cout << mVal << '\n';
    }

    return 0;
}