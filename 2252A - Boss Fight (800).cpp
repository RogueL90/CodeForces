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
        for(int& x:a) cin>>x;
        vector<int> track(1001);
        int sum = 0;
        for(int x :a){
            track[x]++;
            sum+=x;
        }
        int mv = -1;
        int mc = 0;
        for(int i =0; i<1001; i++){
            if(mc<track[i]){
                mc=track[i];
                mv = i;
            }
        }
        if(mc>n-mc+2){
            sum-= mv*(2*mc-n-2);
        }

        cout<<sum<<'\n';

   
}
   
   
return 0;
}