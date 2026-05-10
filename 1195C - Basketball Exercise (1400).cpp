#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;
    vector<long long> row1(size+1, 0);
    vector<long long> row2(size+1, 0);
    for(int i =0; i<size; i++){
        int x;
        cin >> x;
        row1[i] = x;
    }
    for(int i =0; i<size; i++){
        int x;
        cin >> x;
        row2[i] = x;
    }
    for(int i = size-2; i>=0; i--){
        row1[i]+=max(row2[i+1], row2[i+2]);
        row2[i]+= max(row1[i+1], row1[i+2]);
    }
    cout << max(row1[0], row2[0]);

    return 0;
}