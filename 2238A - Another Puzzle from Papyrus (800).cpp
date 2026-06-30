#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin >>n >> c;
        vector<int> b(n,0);
        vector<int> a(n,0);
        for(int i =0; i<n;i++){
            int x;
            cin >>x;
            a[i] = x;
        }
        for(int i =0; i<n;i++){
            int x;
            cin >>x;
            b[i] = x;
        }
        int oC = 0;
        for(int i =0; i<n; i++){
            if(a[i]<b[i]){
                oC = 100000;
                break;
            }
            oC+=a[i]-b[i];
        }
        int aC =c;
        bitset<101> bs;
        for(int i = 0; i<n; i++){
            int curr = b[i];
            int lgt = 100000;
            int lgtI = -1;
            for(int k = 0; k<n; k++){
                if(!bs[k] && a[k]>=curr && a[k]<lgt){
                    lgtI = k;
                    lgt = a[k];
                }
            }
            if(lgtI == -1){
                aC = 100000;
                break;
            }else{
                aC+=lgt-b[i];
                bs.set(lgtI);
            }
        }
        if(min(aC, oC) == 100000){
            cout << -1 << '\n';
        }else{
            cout << min(aC, oC) << '\n';
        }

    }

    return 0;
}