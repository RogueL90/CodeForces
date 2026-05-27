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

    int k, a, b;
    string str;
    cin >> k >> a >> b >> str;
    double avg = (double)str.size()/k;
    if(avg < a || avg > b){
        cout << "No solution";
    }else{
        int round = (int)avg;
        int top = ceil(avg);
        double frac = avg - (int)avg;
        int ind = 0;
        int lineNum = 1;
        while(lineNum < k*frac){
            for(int i =0; i<top; i++){
                cout << str[ind];
                ind++;
            }
            cout << '\n';
            lineNum++;
        }
        while(lineNum <=k){
            for(int i = 0; i<round; i++){
                cout << str[ind];
                ind++;
            }
            if(lineNum ==k){
                if(ind < str.size()){
                    cout << str[ind];
                }
            }else{
                cout << '\n';
            }
            lineNum++;
        }
    }

    return 0;
}