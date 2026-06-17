#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
void dfs(int i, vector<int>& a, int med){
        if(i >=(int)dp.size()) return;
    if (dp[i] != -1) return;

    int maxVal = INT_MIN;
    int s = 0;
    int eq = 0;
    for(int k = i; k<(int)a.size(); k+=2){
        if(a[k] == med){
            eq++;
        }else if(a[k] <med){
            s++;
        }
        if(k!=i){
        if(a[k-1] == med){
        eq++;
        }else if(a[k-1] <med){
            s++;
        }

        }
        if(s<=(k-i+1)/2 && s+eq>(k-i+1)/2){
            if(k+1<(int)dp.size()){
                if(dp[k+1] == -1) dfs(k+1, a, med);
                maxVal = max(maxVal, 1+dp[k+1]);
            }else{
                maxVal = max(maxVal, 1);
            }
        }
    }
    dp[i] = maxVal;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            a[i] =x;
        }
        if(n==1){
            cout << 1<< '\n';
            continue;
        }
        vector<int> dup= a;
        sort(dup.begin(), dup.end());
        int med = dup[n/2];
        dp.assign(n+1, -1);
        dp[n] = 0;
        dfs(0, a, med);
        cout << dp[0] << '\n';
    }

    return 0;
}