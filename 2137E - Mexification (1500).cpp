#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int& x: a)cin>>x;
        sort(a.begin(), a.end());
        int i = 0;
        int prev = -1;
        long long ans =0;
        if(a[i]==0){
            while(i<n){
            if(a[i]==prev){
                ans-=a[i];
                i--;
                prev--;
                break;
            }else if(a[i]==prev+1){
                ans+=a[i];
                prev++;
                i++;
            }else break;
        }
        }
        i--;
        int j = i+1;
        long long side = 0;
        int cnt = 0;
        while(j<n&&prev+1>=a[j]){
            if(prev!=a[j]){
                prev=a[j];
                if(j==n-1||a[j+1]!=a[j]){
                    cnt++;
                    side+=a[j];
                }
            }
            j++;
        }
        j--;
        long long vals = n-1-i;
        int lowest = i==-1?0:a[i]+1;
        if(j==i){
            if(k&1)cout<<ans+vals*lowest<<'\n';
            else cout<<ans+vals*(lowest+(vals==1?0:1))<<'\n';
            continue;
        }
        if(k==1)cout<<ans+(vals-cnt)*(a[j]+1)+side<<'\n';
        else if(k&1)cout<<ans+vals*(lowest+1)<<'\n';
        else cout<<ans+vals*(lowest)<<'\n';
           
    }

    return 0;
}