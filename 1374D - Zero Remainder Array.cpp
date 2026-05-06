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
    for(int l = 0; l<count; l++){
        int n; 
        long long k; 
        cin >> n >> k;
        vector<long long> a(n,0);
        for(int i =0; i<n; i++){
            long long x;
            cin >> x;
            a[i] = x%k;
        }
        sort(a.begin(), a.end());
        long long prev = 0;
        long long streak = 0;
        long long maxStreak = 0;
        for(int i =0; i<n; i++){
            if(a[i] == 0){
                continue;
            }
            if(a[i]!=prev){
                if(streak>0){
                maxStreak = max(maxStreak, (streak-1)*k+(k-prev)+1);
                }
                prev = a[i];
                streak = 1;
            }else{
                streak++;
            }
        }
        if(streak>0){
            maxStreak = max(maxStreak, (streak-1)*k+(k-prev)+1);
        }
        cout << maxStreak << "\n";
    }

    return 0;
}