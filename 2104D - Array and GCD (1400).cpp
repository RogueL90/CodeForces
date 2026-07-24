#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bitset<6000000> bs;
    vector<long long> ps;
    for(int i = 2; i<6e6; i++){
        if(!bs[i]){
            ps.push_back(i+(ps.empty()?0:ps.back()));
            for(int k = i+i; k<6e6; k+=i)
            bs.set(k);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vals(n,0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            vals[i] = x;
        }
        sort(vals.begin(), vals.end());
        long long sum = 0;
        for(int v : vals) sum+=v;
        int curr = n-1;
        int sub = 0;
        while(ps[curr]>sum){
            sum-=vals[sub++];
            curr--;
        }
        cout<<sub<<'\n';
    }


    return 0;
}