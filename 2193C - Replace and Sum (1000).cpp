#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int reps;
    cin >> reps;
    while(reps--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        vector<int> b(n+1);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            a[i+1] = x;
        }
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            b[i+1] = x;
        }
        a[n] = max(a[n], b[n]);
        for(int i = n-1; i>0; i--){
            a[i] = max(b[i], max(a[i+1], a[i]));
        }
        for(int i = 1; i<=n; i++){
            a[i] += a[i-1];
        }
        for(int i = 0; i<q; i++){
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l-1] << " ";
        }
        cout << "\n";

    }

    return 0;
}