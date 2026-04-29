#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int l;
    cin >> n >> l;
    vector<double> locs = {};
    for(int i =0; i<n; i++){
        double val;
        cin >> val;
        locs.push_back(val);
    }
    sort(locs.begin(), locs.end());
    double d = max(l-locs.at(locs.size()-1), locs.at(0));
    for(int i =1; i<n; i++){
        d = max<double>(d, (locs.at(i)-locs.at(i-1))/2);
    }
    cout << fixed << d;


    return 0;
}