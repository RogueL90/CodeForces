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
        int n;
        cin >> n;
        vector<int> ans = {};
        vector<int> pairr(2, 0);
        vector<int> triple(3,0);
        vector<int> pInstr = {0,1, 1, 0, 0, 1, 0, 1};
        vector<int> tInstr = {0, 0, 1, 0, 1, 2, 0, 2, 1, 1, 2, 2};
        while(n>0){
            if(n==3){
                triple = {n, n-1, n-2};
                for(int instr : tInstr){
                    ans.push_back(triple[instr]);
                }
                n-=3;
            }else{
                pairr = {n, n-1};
                for(int instr : pInstr){
                    ans.push_back(pairr[instr]);
                }
                n-=2;
            }
        }
        for(int val : ans){
            cout << val << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}