#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    while(count--){
        int x;
        cin >> x;
        vector<int> vals = {};
        int maxVal = 0;
        for(int i = 0; i<x; i++){
            int y;
            cin >> y;
            vals.push_back(y);
        }
        sort(vals.begin(), vals.end());
        int ans = INT_MAX;
        for(int i = 0; i<x; i++){
            int j = i;
            while(j<x && vals[j] == vals[i]){
                j++;
            }
            int curr = max(x-j, i);
            ans = min(ans, curr);
        }
        cout << ans << '\n';
    }

    return 0;
}