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
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        long long ans = 0;
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            l[i] = x;
        }
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            r[i] = x;
        }
        for(int i =0; i<n; i++){
            if(l[i]>r[i]){
                int temp = l[i];
                l[i] = r[i];
                r[i] = temp;
            }
            ans+=r[i]-l[i];
        }
        vector<int> arr(n, 0);
        for(int i = 0; i<n; i++){
            arr[i] = i;
        }
        sort(arr.begin(), arr.end(), [&](int c, int d){return l[c]<l[d];});
        int minGap = INT_MAX;
        for(int i =0; i<n-1; i++){
            if(r[arr[i]]>=l[arr[i+1]]){
                minGap = 0;
                break;
            }else{
                minGap = min(minGap, l[arr[i+1]]-r[arr[i]]);
            }
        }
        cout<< ans+2*minGap<<'\n';
    }

    return 0;
}