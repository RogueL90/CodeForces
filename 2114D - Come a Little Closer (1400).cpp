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
        vector<pair<int, int>> c;
        int l1 = -1;
        int l2 = -1;
        int r1 = -1;
        int r2 = -1;
        int u1 = -1;
        int u2 = -1;
        int d1 = -1;
        int d2 = -1;
        for(int i =0; i<n; i++){
            int x, y;
            cin>>x>>y;
            int cu = c.size();
            if(l1<0 || x<=c[l1].first){
                l2 = l1;
                l1 = cu;
            }else if(l2<0 || x<c[l2].first){
                l2 = cu;
            }
            if(r1<0 || x>=c[r1].first){
                r2 = r1;
                r1 = cu;
            }else if(r2< 0 ||x>c[r2].first){
                r2 = cu;
            }
            if(u1<0 || y>=c[u1].second){
                u2 = u1;
                u1 = cu;
            }else if(u2<0 || y>c[u2].second){
                u2 = cu;
            }
            if(d1<0||y<=c[d1].second){
                d2 = d1;
                d1 = cu;
            }else if(d2<0||y<c[d2].second){
                d2 = cu;
            }
            c.push_back({x, y});
        }
        long long minCoins = LLONG_MAX;
        unordered_set<int> ms = {};
        ms.insert(r1);
        ms.insert(u1);
        ms.insert(d1);
        ms.insert(l1);
        for(int curr : ms){
            long long r = curr == r1?c[r2].first:c[r1].first;
            long long l = curr == l1?c[l2].first:c[l1].first;
            long long u = curr == u1?c[u2].second:c[u1].second;
            long long d = curr == d1?c[d2].second:c[d1].second;
            long long cv = (r-l+1)*(u-d+1);
            if(cv==n-1){
                cv+=min(r-l+1, u-d+1);
            }
            minCoins = min(minCoins, cv);

        }
        cout<<minCoins<<'\n';

    }

    return 0;
}