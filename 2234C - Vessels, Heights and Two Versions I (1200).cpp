#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> h(n, 0);
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            h[i] = x;
        }
        for(int i = 0; i<n; i++){
            vector<int> w(n, 0);
            vector<int> v(n, 0);
            w[i] = h[i];
            int k = (i+1)%n;
            while(k!=i){
                w[k]= max(h[(k-1+n)%n], w[(k-1+n)%n]);
                k= (k+1)%n;
            }
            v[(i-1+n)%n] = h[(i-1+n)%n];
            k = (k-2+n)%n;
            while(k!=i){
                v[k]= max(h[k], v[(k+1)%n]);
                k= (k-1+n)%n;
            }
            long long sum = 0;
            for(int m = 0; m<n; m++){
                sum+=min(w[m], v[m]);
            }
            cout << sum << " ";
        }
        cout << '\n';
        }

    return 0;
}