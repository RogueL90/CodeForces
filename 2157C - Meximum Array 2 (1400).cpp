#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin>>cases;
    while(cases--){
        int n, k, q;
        cin >>n>>k>>q;
        vector<int> ans(n, 101);
        vector<int> rA = {};
        vector<int> lA = {};
        for(int i =0; i<q; i++){
            int c, r, l;
            cin >>c>>r>>l;
            if(c==1){
                for(int j = r-1; j<l; j++){
                    ans[j] = k;
                }
            }else{
                rA.push_back(r-1);
                lA.push_back(l);
            }
        }
        int ind = 0;
        for(int i =0; i<(int)rA.size(); i++){
            for(int m = rA[i]; m<lA[i]; m++){
                if(ans[m]==k){
                ans[m] = 102;
            }else if(ans[m]==101){
                ans[m] = -1;
            }
            }
        }
        for(int i =0; i<n; i++){
            if(ans[i]==-1)ans[i]=(ind++%k);
        }
        for(int curr: ans){
            cout << curr<<" ";
        }
        cout <<'\n';
    }

    return 0;
}