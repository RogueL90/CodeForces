#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> opens(n, 0);
        vector<int> streak(n, 0);
        opens[n-1] = s[n-1]=='(';
        streak[n-1] = 1-opens[n-1];
        for(int i = n-2; i>=0; i--){
            if(s[i]=='('){
                opens[i] = opens[i+1]+1;
                streak[i] = 0;
            }else{
                streak[i] = streak[i]+1;
                opens[i] = opens[i+1];
            }
        }
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(s[i]==')' && opens[i]>streak[i]){
                ans = n-streak[i]*2;
                break;
            }
        }
        cout << ans << '\n';

    }

    return 0;
}