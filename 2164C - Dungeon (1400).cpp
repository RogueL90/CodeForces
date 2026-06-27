#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n>> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            pq.push(x);
        }
        vector<int> mon(m, 0);
        vector<int> c(m, 0);
        for(int i =0; i<m ; i++){
            int x;
            cin >> x;
            mon[i] = x;
        }
        for(int i =0; i<m; i++){
            int x;
            cin >> x;
            c[i] = x;
        }
        int cnt = 0;
        vector<int> sharpen = {};
        vector<int> finish = {};
        vector<int> sw;
        sw.reserve(n);
        for(int i =0; i<m; i++){
            if(c[i]!=0){
                sharpen.push_back(i);
            }else{
                finish.push_back(i);
            }
        }
        sort(sharpen.begin(), sharpen.end(), [&](int a, int b){return mon[a]<mon[b];});
        sort(finish.begin(), finish.end(), [&](int a, int b){return mon[a]<mon[b];});
        int ind = 0;
        while(ind<(int)sharpen.size() && !pq.empty()){
            int curr = pq.top();
            pq.pop();
            if(curr<mon[sharpen[ind]]) sw.push_back(curr);
            else {
                curr = max(curr, c[sharpen[ind]]);
                pq.push(curr);
                ind++;
                cnt++;
            }
        }
        while(!pq.empty()){
            sw.push_back(pq.top());
            pq.pop();
        }
        ind = sw.size()-1;
        for(int i = finish.size()-1; i>=0 && ind>=0;i--){
            if(sw[ind]>=mon[finish[i]]){
                cnt++;
                ind--;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}