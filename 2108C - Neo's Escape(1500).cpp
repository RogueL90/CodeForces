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
        vector<int> a(n);
        for(int& x : a)cin>>x;
        vector<int> ans;
        int p = 0;
        while(p<n-1){
            int status;
            if(a[p]<a[p+1]){
                status = 2;
            }else if(a[p]>a[p+1]){
                status = 0;
            }else{
                status = 1;
            }
            p+=2;
            while(p<n){
                if(a[p-1]<a[p]){
                    if(status == 0)break;
                    status = 2;
                }else if(a[p-1]>a[p]){
                    if(status == 2)break;
                    status = 0;
                }
                p++;
            }
            ans.push_back(status);
        }
        if(p==n-1)ans.push_back(1);
        int as = ans.size();
        int clones =0;
        for(int i =0; i<as; i++){
            clones++;
            if(i+1<as&&ans[i]==2&&ans[i+1]==0)i++;
            else if(i>0&&ans[i]==1){
                if(ans[i-1]==2)clones--;
            }
        }
        cout<<clones<<'\n';
    }

    return 0;
}