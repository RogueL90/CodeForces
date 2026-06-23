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
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            a[i] = x;
        }
        map<int, int> cnt1 = {};
        map<int, int> cnt2 = {};
        int val1 = a[0];
        cnt1[val1] = 1;
        cnt2[val1] = 0;
        if(val1 != 1){
        int its =0;
        while(val1!=1){
            its++;
            if(val1 & 1){
                val1++;
            }else{
                val1 >>=1;
            }
            cnt1[val1]++;
            cnt2[val1]+=its;
        }}else{
            cnt2[2]++;
                    cnt1[2]++;
        }
        for(int i =1; i<n; i++){
            int val = a[i];
            int it = 0;
            if(cnt1.contains(val)){
                        cnt1[val]++;
                        cnt2[val]+=it;
                }
                if(val == 1){
                    cnt2[2]+=1;
                    cnt1[2]++;
                }
                while(val!=1){
                    it++;
                    if(val & 1){
                        val++;
                    }else{
                        val>>=1;
                    }
                    if(cnt1.contains(val)){
                        cnt1[val]++;
                        cnt2[val]+=it;
                    }
                }
        }
        int ans = INT_MAX;
        for(const auto& [key, val] : cnt1){
            if(val == n){
                ans = min(ans, cnt2[key]);
            }
        }
        cout << ans << '\n';

    }

    return 0;
}