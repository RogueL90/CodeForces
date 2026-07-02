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
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        while(n--){
            int x;
            cin >> x;
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        cout << maxVal-minVal+1 << '\n';
    }

    return 0;
}