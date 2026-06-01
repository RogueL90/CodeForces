#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <optional>
using namespace std;

const int mod = 1000000007;
int dfs(vector<optional<pair<int, int>>>& tree, vector<int>& ans, int ind){
    if(ans[ind]) return ans[ind];
    ans[ind] = (3 + dfs(tree, ans, tree[ind]->first) + dfs(tree, ans, tree[ind]->second))%mod;
    return ans[ind];
}

void dfs2(vector<optional<pair<int, int>>>& tree, vector<int>& ans, int ind, int addVal){
    ans[ind]=(ans[ind]+addVal)%mod;
    if(tree[ind].has_value()){
        dfs2(tree, ans, tree[ind]->first, ans[ind]);
        dfs2(tree, ans, tree[ind]->second, ans[ind]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    while(count--){
        int n;
        cin >> n;
        vector<optional<pair<int, int>>> tree(n+1, nullopt);
        for(int i = 1; i<= n; i++){
            int x, y;
            cin >> x >> y;
            if(x==0) continue;
            tree[i] = make_pair(x, y);
        }
        vector<int> ans(n+1, 0);
        for(int i = 1; i<=n; i++){
            if(!tree[i].has_value()){
                ans[i] = 1;
            }
        }
        dfs(tree, ans, 1);
        dfs2(tree, ans, 1, 0);
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}