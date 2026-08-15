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
        for(int i = 0; i<n-1; i++){
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        queue<int> q;
        vector<bool> taken(n+1, false);
        taken[1] = true;
        q.push(1);
        int maxNodes = 1;
        int maxChildren = 0;
        while(!q.empty()){
            int s = q.size();
            maxNodes = max(maxNodes, s);
            while(s--){
                int curr = q.front();
                maxChildren = max(maxChildren, (int)tree[curr].size()+(curr==1?1:0));
                q.pop();
                for(auto& c : tree[curr]){
                    if(taken[c])continue;
                    taken[c] = true;
                    q.push(c);
                }
            }
        }
        cout<<max(maxNodes, maxChildren)<<'\n';
    }

    return 0;
}