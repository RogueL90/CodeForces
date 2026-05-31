#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long h;
    cin >> n >> h;
    long long ans = 0;
    long long curr = pow(2, n);
    n+=1;
    while(n--){
        ans+=min(h, curr);
        curr/=2;
    }
    cout << ans;

    return 0;
}