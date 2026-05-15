#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;
    for(count = count; count>0; count--){
        int v;
        int e;
        cin >> v >> e;
        vector<int> color(v+1, 2);
        vector<vector<int>> edges(v+1, vector<int>());
        for(e = e; e>0; e--){
            int v1;
            int v2;
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }

        int count = 0;
        for(int i =1; i<=v; i++){
            if(color[i] != 2){
                continue;
            }
            bool valid = true;
            deque<int> que = {};
            que.push_back(i);
            color[i] = 0;
            int time = 1;
            vector<int> cnt(2, 0);
            cnt[0]++;
            while(!que.empty()){
                int curr = time % 2;
                int size = que.size();
                for(int k =0; k<size; k++){
                    int val = que.front();
                    que.pop_front();
                    for(int vals : edges[val]){
                        if(color[vals] == 2){
                            que.push_back(vals);
                            color[vals] = curr;
                            cnt[curr]++;
                        } else if(color[vals] != curr){
                            valid = false;
                        }
                    }
                }
                time++;
            }
            if(valid){
                count+=max(cnt[0], cnt[1]);
            }
        }
        cout << count << "\n";
        


    }

    return 0;
}