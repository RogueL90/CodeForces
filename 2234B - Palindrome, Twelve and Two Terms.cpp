#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        long long n;
        cin >> n;
        long long ans = n/12;
        if(n%12 == 10){
            if(n<22){
                cout << -1 << '\n';
            } else{
                cout << 22 << " " << (ans-1)*12 << '\n';
            }
        }else{
            cout << n%12 << " " << (ans)*12 << '\n';
        }
    }

    return 0;
}