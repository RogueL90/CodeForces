#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
# include <bitset>
using namespace std;

string s;
int n;
int k;
int eval(bitset<5000>& bs){
    int open = 0;
    int pairs = 0;
    for(int i =0; i<n; i++){
        if(bs[i]) continue;
        char c = s[i];
        if(c == '('){
            open++;
        }else if(c==')' && open){
            pairs++;
            open--;
        }
    }
    return pairs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        cin >> n >> k;
        cin >> s;
        bitset<5000> bs;
        int ind = 0;
        int kk = k;
        vector<int> opens = {};
        while(ind<n && kk){
            if(s[ind] == '('){
                opens.push_back(ind);
                kk--;
                bs.set(ind);
            }
            ind++;
        }
        ind = n-1;
        while(ind>=0 && kk){
            if(s[ind] == ')'){
                kk--;
                bs.set(ind);
            }
            ind--;
        }
        int ans = eval(bs);
        bitset<5000> ansb = bs;

        while(ind >=0 && !opens.empty()){
            if(s[ind] == '('){
                ind--;
                continue;
            }
            bs.set(ind);
            bs.reset(opens.back());
            opens.pop_back();
            int newV= eval(bs);
            if(newV<ans){
                ans = newV;
                ansb = bs;
            }
            ind--;
        }

        for(int i = 0; i<n; i++){
            cout << ansb[i];
        }
        cout << '\n';
    }

    return 0;
}