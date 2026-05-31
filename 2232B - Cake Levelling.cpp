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
        vector<int> heights(n);
        for(int i =0 ; i<n;i++){
            int y;
            cin >> y;
            heights[i] = y;
        }
        int extra = 0;
        int prevH = heights[0];
        cout << prevH << " ";
        for(int i = 1; i<n; i++){
            if(prevH < heights[i]){
                extra+=heights[i]-prevH;
            }else if(prevH > heights[i]){
            long long diff = prevH - extra - heights[i];

            if(diff > 0){
            long long k = (diff + i) / (i + 1); 
            extra += k * i;
            prevH -= k;
        }

    extra -= (prevH - heights[i]);
}
            cout << prevH << " ";
        }
        cout << '\n';
    }

    return 0;
}