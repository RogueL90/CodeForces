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
    for(int tc =0; tc<count; tc++){
        int n, m;
        cin >> n >>  m;
        long long count = n;
        vector<bool> track(m, false);
        vector<vector<int>> vec(n+1, vector<int>());

        for(int i =0; i<m; i++){
            int x, y;
            cin >> x >> y;
            vec[x].push_back(i);
            vec[y].push_back(i);
        }

        int left = 1;
        int right =1;

        while(right <=n ){
            for(int pairNum : vec[right]){
                if(!track[pairNum]){
                    track[pairNum] = true;
                }else{
                    while(track[pairNum]){
                        for(int pNum : vec[left]){
                            track[pNum] = false;
                        }
                        left++;
                    }
                }
            }
            count += (right-left);
            right++;
        }
        cout << count << "\n";
    }

    return 0;
}