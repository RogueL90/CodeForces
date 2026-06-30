#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i =1; i<=n; i++){
            int x;
            cin >>x;
            a[i]=x;
        }
        long long ans =0;
        vector<vector<int>> tree(n+1, vector<int>());
        for(int i =0;i<n-1; i++){
            int x, y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        

    }

    return 0;
}