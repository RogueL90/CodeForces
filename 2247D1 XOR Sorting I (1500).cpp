#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> a(n);
        for(int& x : a)cin>>x;
        int ans =-1;
        while(true){
            int curr = pow(2, ans+1);
            int i = 0; 
            int prevMax = -1;
            bool valid = true;
            while(i<n){
                int currMax = -1;
                int currMin = INT_MAX;
                for(int k = 0; k<curr&&i<n; k++){
                    currMax = max(currMax, a[i]);
                    currMin = min(currMin, a[i]);
                    i++;
                }
                if(currMin<prevMax){
                    valid = false;
                    break;
                }else{
                    prevMax = currMax;
                }
            }
            if(valid)break;
            ans++;
        }
        cout<< (int)pow(2, ans)<<'\n';
    }

    return 0;
}