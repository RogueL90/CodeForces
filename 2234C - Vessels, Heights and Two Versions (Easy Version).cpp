#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    while(count--){
        int n;
        cin >> n;
        vector<int> vs = {};
        for(int i =0; i<n; i++){
            int h;
            cin >> h;
            vs.push_back(h);
        }
        for(int i = 0; i<n; i++){
            vector<int> arr(n, 0);
            for(int k = i;k != (i-1+n)%n; k=(k+1)%n){
                int next = (k+1)%n;
                arr[next] = max(arr[k], vs[k]);
            }
            if(arr[n-1]>vs[i]){
                for(int k = (i-1+n)%n;k != i; k=(k-1+n)%n){
                int next = (k+1)%n;
                arr[k] = min(vs[k], arr[next]);
            }
            }

            long long sumA = 0;
            for(int val : arr){
                sumA+=val;
            }
            cout << sumA << " ";
        }
        cout << '\n';
    }

    return 0;
}