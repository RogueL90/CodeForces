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

    int cases;
    cin >> cases;
    while(cases--){
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int wOut = ceil(double(n)/(x+y));
        int w;
        if(x*z >=n){
            w = wOut;
        }else{
            w = z;
            n-=x*z;
            w+=ceil(double(n)/(x+10*y));
        }
        cout << min(w, wOut) << '\n';
    }

    return 0;
}