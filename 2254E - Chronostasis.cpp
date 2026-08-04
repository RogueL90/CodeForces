#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
using ll = long long;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> b(n, 0);
        for(ll& x : b)cin>>x;
        ll sum = 0;
        vector<ll> bp;
        multiset<ll> bn;
        for(int i = 0; i<n; i++)
        {
            sum+=b[i];
            if(b[i]>0)bp.push_back(b[i]);
        else bn.insert(b[i]);
        }
        if(sum<=0){
            cout<<-1<<'\n';
            continue;
        }
        vector<ll> ans;
        ans.reserve(n);
        sort(bp.begin(), bp.end());
        ans.push_back(bp[0]);
        int i = 1;
        while(i<n||!bn.empty()){
            auto it = bn.lower_bound(-ans.back()+1);
            if(it!=bn.end()){
                ans.push_back(*it+ans.back());
                bn.erase(it);
            }else{
                ans.push_back(bp[i]+ans.back());
                i++;
            }
        }
        for(int i =0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        


    }

    return 0;
}