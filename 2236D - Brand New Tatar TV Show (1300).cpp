#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n, l;
        cin >> n >> l;
        vector<int> arr(n+1, 0);
        while(n--){
            int x;
            cin >> x;
            arr[x]++;
        }
        bool doable = false;
        for(int curr : arr){
            if(!curr) continue;
            if(!(curr &1))doable = true;
        }
        if(!doable){
            for(int i =0; i<arr.size(); i++){
                if(arr[i]){
                    for(int k = i+1;k<min(i+l+1, int(arr.size())); k++){
                        if(arr[k]){
                            doable = true;
                            break;
                        }
                    }
                    if(doable) break;
                    i+=l-1;
                }
            }
        }
        if(doable){
                cout <<"YES";
            }else{
                cout <<"NO";
            }
        cout << '\n';
    }

    return 0;
}