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
    int m;
    cin >> n >> m;
    vector<vector<int>> r(n);
    vector<vector<int>> c(m);
    for(int i =0; i<n; i++){
        for(int k = 0; k<m; k++){
            char curr;
            cin >> curr;
            if(curr == '#'){
                r[i].push_back(k);
                c[k].push_back(i);
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(r[i].empty()){
            continue;
        } 
        vector<int> vec = c[r[i][0]];
        for(int k = 1; k<r[i].size(); k++){
            if(c[r[i][k]] != vec){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}