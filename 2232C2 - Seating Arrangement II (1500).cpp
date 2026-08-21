#include <bits/stdc++.h>
using namespace std;


int cnt(string& u, int ambiIntros, int tables, int seats){
    int total = 0;
    int ex = 0;
    int in = tables;
    for(char c : u){
        if(c=='I'){
            if(in){
                in--;
                total++;
                ex+=seats-1;
            }
        }else if(c=='E'){
            if(ex){
                ex--;
                total++;
            }
        }else{
            if(ambiIntros){
                ambiIntros--;
                if(in){
                in--;
                total++;
                ex+=seats-1;
            }
            }else{
                if(ex){
                ex--;
                total++;
            }
            }
        }
    }
    return total;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, x, s;
        cin>>n>>x>>s;
        string u;
        cin>>u;
        int l = 1;
        int r = 0;
        for(int i =0; i<n; i++){
            if(u[i]=='A')r++;
        }
        int ans = cnt(u, 0, x, s);
        while(l<=r){
            int mid = l+(r-l)/2;
            int first = cnt(u, mid-1, x, s);
            int second = cnt(u, mid, x, s);
            if(first<second){
                ans = max(ans, second);
                l = mid+1;
            }else if(second<first){
                ans=max(first, ans);
                r = mid-2;
            }else{
                ans = first;
                break;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}