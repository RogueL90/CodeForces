#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ps(1000001, -1);
    vector<int> pl(1000001, -1);
    for(int i = 2;i<=500000; i++){
        if(ps[i]!=-1)continue;
        for(int k = 2*i; k<1000001; k+=i){
            if(ps[k]==-1)ps[k] = i;
            pl[k] = i;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto& x:a)cin>>x;
        int largestPrime = 0;
        bool Alice = false;
        int largest = -1;
        for(int i =0; i<n; i++){
            if(a[i]<largest){
                largest = -2;
                break;
            }
            largest = a[i];
        }
        if(largest == -2)
        for(int i =0; i<n; i++){
            if(pl[a[i]]==-1){
                if(a[i]<largestPrime){
                    Alice = true;
                    break;
                }
                largestPrime = max(largestPrime, a[i]);
            }
            else {
                largestPrime = max(largestPrime, pl[a[i]]);
                if(largestPrime >ps[a[i]]){
                    Alice = true;
                    break;
                }
            }
        }
        if(Alice){
            cout<<"Alice"<<'\n';
        }else{
            cout<<"Bob"<<'\n';
        }
    }

    return 0;
}