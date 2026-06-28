#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<int> p(n-1,0);
        for(int i =0; i<n-1; i++){
            int x;
            cin >>x;
            p[i] =x;
        }
        ll ans = n;
        vector<vector<int>> tree(n+1, vector<int>());
        for(int i = 1; i < n; i++){
        tree[p[i-1]].push_back(i+1); 
        }
        queue<int> que = {};
        vector<int> h(n+1, 0);
        que.push(1);
        int ch = 0;
        while(!que.empty()){
            ch++;
            int size = que.size();
            for(int i =0; i<size; i++){
                int curr = que.front();
                que.pop();
                for(int c : tree[curr]){
                    h[c]=ch;
                    que.push(c);
                }
            }
        }
        vector<int> h1 = h;

        for(int i = n; i >=1; i--){
            for(int c : tree[i]){
                h1[i] = max(h1[i], h1[c]);
            }
        }



        for(int i =0; i<(int)tree.size(); i++){
            vector<int>& curr = tree[i];
            if(curr.size()<2)continue;
            int currH = h[i];
            int fb = 0;
            int sb = 0;
            for(int c : curr){
                if(h1[c]>=fb){
                    sb = fb;
                    fb = h1[c];
                }else if(h1[c]>sb){
                    sb = h1[c];
                }
            }
            ans+=sb-currH;
        }
        cout << ans << '\n';
    }

    return 0;
}