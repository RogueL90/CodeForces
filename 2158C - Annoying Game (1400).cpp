#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    while(count--){
        int n, k;
        cin >> n >> k;
        vector<long long> a(n+1);
        vector<int> b(n);
        a[0] = 0;
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            a[i] = x+a[i-1];
        }
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            b[i] = x;
        }
    
        vector<long long> minim(n+1);
        vector<long long> maxim(n+1);
        minim[0] = 0;
        maxim[n] = a[n];
        for(int i = 1; i<=n; i++){
            minim[i] = min(minim[i-1], a[i]);
        }
        for(int i = n-1; i>=0; i--){
            maxim[i] = max(maxim[i+1], a[i]);
        }
        long long ans = -1000000001;
        if(k & 1) {
            for(int i = 1; i<=n; i++){
                ans = max(ans, maxim[i] - minim[i-1] + b[i-1]);
            }
        }else{
            for(int i = 1; i<=n; i++){
                ans = max(ans, maxim[i] - minim[i-1]);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}