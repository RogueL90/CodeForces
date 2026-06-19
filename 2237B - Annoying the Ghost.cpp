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
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            a[i] = x;
        }
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            b[i] = x;
        }
        int swaps = 0;
        for(int i =0; i<n; i++){
            int k = i; 
            while(k<n && a[k]>b[i]){
                k++;
            }
            if(k == n){
                swaps = -1;
                break;
            }
            while(k != i){
                swaps++;
                int temp = a[k];
                a[k] = a[k-1];
                a[k-1] = temp;
                k--;
            }
        }
        cout << swaps << '\n';
    }

    return 0;
}