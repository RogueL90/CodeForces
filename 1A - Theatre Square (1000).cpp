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

    double n;
    double m;
    int a;
    cin >> n >> m >> a;
    long long val = (ceil(n/a))*ceil(m/a);
    cout << val;

    return 0;
}