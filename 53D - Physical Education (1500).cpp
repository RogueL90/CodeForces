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
    cin >> n;
    vector<int> curr(n);
    vector<int> goal(n);
    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        goal[i] = x;
    }
    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        curr[i] = x;
    }
    vector<int> swaps = {};
    for(int i =0; i<n; i++){
        if(curr[i] == goal[i]){
            continue;
        }
        int j = i+1;
        while(curr[j] != goal[i]){
            j++;
        }
        while(j!=i){
            swaps.push_back(j);
            int temp = curr[j];
            curr[j] = curr[j-1];
            curr[j-1] = temp;
            j--;
        }
    }
    cout << swaps.size() << '\n';
    for(int i = 0; i<swaps.size(); i++){
        cout << swaps[i] << " " << swaps[i]+1 << '\n';
    }

    return 0;
}