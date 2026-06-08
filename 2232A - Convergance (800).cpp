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
        int n;
        cin >> n;

        vector<int> arr(n);
        long long total = 0;
        for(int i =0; i<n; i++){
            int y;
            cin >> y;
            arr[i] = y;
            total+=y;
        }
        long long inSum = total;
        long long ans = 0;
        for(int i = n-1; i>=0; i--){
            long long curr = arr[i];
            long long prev = total - inSum;
            inSum -= curr;
            ans = max(ans, ans + inSum - curr*i-curr*(n-1-i)+prev);
        }
        cout << ans << '\n';
    }

    return 0;
}