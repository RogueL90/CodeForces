#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a(1000001, 0);
    int val = a.size();
    for(int i =2; i*i<val; i++){
        if(!a[i]){
            int c = i*i;
                while(c<val){
                    a[c]=-1;
                    c+=i;
                }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt = 0;
        int primes = 0;
        for(int i =2; i*i<=n; i++){
            if(!a[i]){
                if(n%i==0) cnt++;
                while(n%i==0){
                    n/=i;
                    primes++;
                }
            }
        }
        if (n > 1) {
            cnt++;
            primes++;
        }
        cout<<primes+cnt-1<<'\n';
    }

    return 0;
}