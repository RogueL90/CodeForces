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
        vector<int> a(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            a[i] = x;
        }
        sort(a.begin(), a.end());
        int dist = (n-k-1)/2;
        int start = a[dist];
        int end = a[n-1-dist];
        cout<<end-start+1<<'\n';
    }

    return 0;
}