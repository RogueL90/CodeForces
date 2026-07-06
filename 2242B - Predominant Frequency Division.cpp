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
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        bool done = false;
        vector<int> pre1(n, 0);
        if(a[0]==1)pre1[0] = 1;
        else pre1[0]=-1;
        for(int i = 1; i<n; i++){
            pre1[i]=pre1[i-1];
            if(a[i]==1)pre1[i]++;
            else pre1[i]--;
        }
        vector<int> pre2(n+1, 0);
        for(int i = n-2; i>=0; i--){
            pre2[i] = pre2[i+1];
            if(a[i]<=2){
                pre2[i] = max(pre2[i]+1, 1);
            }
            else pre2[i]--;
        }
        for(int i =0; i<n-2; i++){
            if(pre1[i]>=0&& pre2[i+1]>=0){
                done = true;
                break;
            }
        }

        if(!done)
        cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';

    }

    return 0;
}