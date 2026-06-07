#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> vec = {};
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            vec.push_back(x);
        }
            sort(vec.begin(), vec.end(), greater<>());
            bool pat = true;
            int curr = vec[0]%vec[1];
            for(int i = 2; i<n; i++){
                if(curr == vec[i]){
                    curr = vec[i-1]%vec[i];
                }else{
                    pat = false;
                    break;
                }
            }
            if(pat){
                cout << vec[0] << " " << vec[1] << '\n';
            }else{
                cout << -1 << '\n';
            }
    }

    return 0;
}