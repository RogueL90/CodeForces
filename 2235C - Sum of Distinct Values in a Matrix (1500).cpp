#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m, z, y;
        cin>>n>>m>>z>>y;
        vector<int> track(n+m+1, 0);
        vector<int> a1(z);
        vector<int> b1(y);
        for(int& x: a1){
            cin>>x;
            track[x]++;
        }
        for(int& x: b1){
            cin>>x;
            track[x]++;
        }
        vector<int> dup;
        vector<int> a;
        vector<int> b;
        for(int x : a1){
            if(track[x]==2)dup.push_back(x);
            else a.push_back(x);
        }
        for(int x : b1){
            if(track[x]!=2)b.push_back(x);
        }
        int v = m+n-1;
        vector<int> total;
        total.reserve(n+m+dup.size());
        for(int c : dup)total.push_back(c);
        for(int i = a.size()-1; i>=0 && n; i--){
            total.push_back(a[i]);
            n--;
        }
        for(int i = b.size()-1; i>=0 && m; i--){
            total.push_back(b[i]);
            m--;
        }
        sort(total.begin(), total.end());
        long long sum = 0;
        for(int i = total.size()-1; i>=0&&v; i--){
            sum+=total[i];
            v--;
        }
        cout<<sum<<'\n';


    }

    return 0;
}