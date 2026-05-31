#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int solve(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int right = arr.size()-1;
    int left = 0;
    int profit = 0;
    while(left < right){
        profit+=arr[right--];
        profit-=arr[left++];
    }
    return profit;
}
 
int main() {
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    cout << solve(n, arr) << endl;
}
