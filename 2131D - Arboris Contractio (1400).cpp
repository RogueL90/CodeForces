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
        vector<vector<int>> tree(n+1, vector<int>());
        for(int i =0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<bool> leaf(n+1, false);
        int leafCount = 0;
        for(int i = 1; i<=n; i++){
            if(tree[i].size()<=1){
                leaf[i] = true;
                leafCount++;
            }
        }
        int maxLeafC = INT_MIN;
        for(int i = 1;i<=n; i++){
            int currLeafC = 0;
            for(int c : tree[i]){
                if(leaf[c])currLeafC++;
            }
            if(leaf[i])currLeafC++;
            maxLeafC = max(maxLeafC, currLeafC);
        }
        cout<<leafCount-maxLeafC<<'\n';
        
    }

    return 0;
}