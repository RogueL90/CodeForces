#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    cin >> i;
    for(i = i; i>0; i--){
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int k = 0; k<n; k++){
            cin >> arr[k];
        }
        sort(arr.begin(), arr.end());
        int currSize = 1;
        int maxSize = 0;
        for(int k = 1; k<n; k++){
            if(arr[k] == arr[k-1]){
                currSize++;
            }else{
                maxSize = max(maxSize, currSize);
                currSize =1;
            }
        }
        maxSize = max(maxSize, currSize);
        cout << max(n%2 == 0?0:1, maxSize-n+maxSize) << "\n";
    }

    return 0;
}