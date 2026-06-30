#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        string str;
        cin>>str;
        int num = 0;
        int curr ='2';
        for(char c : str){
            if(c!=curr){
                curr = c;
                num++;
            }
        }
        num = num>2?1:num;
        cout << num<<'\n';
    }

    return 0;
}