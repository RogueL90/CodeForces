#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> vals(m, 0);
        for(int i =0; i<m; i++){
            int x;
            cin>>x;
            vals[i] =x;
        }
        sort(vals.begin(), vals.end());
        for(int i =0; n>0; i++){
            n--;
            int val1 = vals[i];
            int val2 = vals[m-1-i];
            for(int k = 0; k<3; k++){
                cout << val1<<" "<<val2<<" ";
            }
            cout<<'\n';
            if(n==0) break;
            n--;
            for(int k = 0; k<3; k++){
                cout << val2<<" "<<val1<<" ";
            }
            cout<<'\n';
        }
    }

    return 0;
}