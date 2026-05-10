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
    int prev = 0;
    int ans = 0;
    for(int i =0; i<n; i++){
        int x;;
        cin >> x;

        if(x==1){
            if(prev == 1){
                ans++;
                prev = 0;
            }else{
                prev = x;
            }
        } else if(x==2){
            if(prev == 2){
                ans++;
                prev = 0;
            }else{
                prev = x;
            }
        } else if(x==3){
            if(prev == 1){
                prev = 2;
            } else if(prev == 2){
                prev = 1;
            } else{
                prev = x;
            }
        } else{
            prev = 0;
            ans++;
        }
    }
    cout << ans;
    return 0;
}