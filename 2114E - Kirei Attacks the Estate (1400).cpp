#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<long long>& minD, vector<long long>& maxD, vector<int>& da, int val, int ignore){
    maxD[val] = da[val] + max(-minD[ignore], 0LL);
    minD[val] = da[val] - max(maxD[ignore], 0LL);
    for(int v : graph[val]){
        if(v == ignore) continue;
        dfs(graph, minD, maxD, da, v, val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> da(n+1, 0);
        for(int i = 1; i<=n; i++){
            int d;
            cin >> d;
            da[i] = d;
        }
        vector<vector<int>> graph(n+1, vector<int>());
        for(int i = 1; i<n; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<long long> maxD(n+1, INT_MIN);
        vector<long long> minD(n+1, INT_MAX);
        dfs(graph, minD, maxD, da, 1, 0);
        for(int i =1; i<=n; i++){
            cout << maxD[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}