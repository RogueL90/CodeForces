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
        vector<int> line = {};
        for(int i = 0; i< n; i++){
            int next;
            cin >> next;
            line.push_back(next);
        }
        int left = (n-1)/2-1;
        int right = n/2+1;
        int db = n & 1 ? 0 : line[left+1] == line[right-1] ? 1 : 0;
        while(left >= 0 && right <n){
            int stay = 0;
            if(line[left] == line[left+1]) stay++;
            if(line[right-1] == line[right]) stay++;
            int swap = 0;
            if(line[right] == line[left+1]) swap++;
            if(line[right-1] == line[left]) swap++;
            if(swap < stay){
                int temp = line[left];
                line[left] = line[right];
                line[right] = temp;
                db+=swap;
            }else{
                db+=stay;
            }
            left--;
            right++;
        }
        cout << db << '\n';
    }

    return 0;
}