#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n, m;
        cin >> n >> m;
        priority_queue<int> a;
        priority_queue<int> b;
        for(int i =0; i<n; i++){
            int x;
            cin >> x;
            a.push(x);
        }
        for(int i =0; i<m; i++){
            int x;
            cin >> x;
            b.push(x);
        }
        bool alice = true;
        while(!a.empty() && !b.empty()){
            if(alice){
                if(a.top()>=b.top()){
                    b.pop();
                }else{
                    int curr = b.top();
                    b.pop();
                    curr -= a.top();
                    b.push(curr);
                }
            }else{
                if(a.top()<=b.top()){
                    a.pop();
                }else{
                    int curr = a.top();
                    a.pop();
                    curr-=b.top();
                    a.push(curr);
                }
            }
            alice = !alice;
        }
        cout << (alice ? "Bob" : "Alice") << '\n';
    }

    return 0;
}