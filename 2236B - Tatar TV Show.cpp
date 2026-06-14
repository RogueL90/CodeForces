
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        bool valid = true;
        for(int i = 0; i<k; i++){
            int curr =i;
            int oc= 0;
            while(curr <n){
                if(str[curr] == '1') oc++;
                curr+=k;
            }
            if((oc & 1)){
                valid = false;
            }
        }
        if(valid){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}