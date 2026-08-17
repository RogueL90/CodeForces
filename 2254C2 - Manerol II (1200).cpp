#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int cnt0a = 0;
        int cnt0b = 0;
        int cnt1b = 0;
        int cnt1a = 0;
        vector<int> c0a, c0b, c1a, c1b;
        for(int i = 0; i<n; i+=2){
            if(a[i]=='0')cnt0a++;
            else c0a.push_back(i/2);
            if(b[i]=='0')cnt0b++;
            else c0b.push_back(i/2);
        }
        for(int i = 1; i<n; i+=2){
            if(a[i]=='0')cnt1a++;
            else c1a.push_back(i/2);
            if(b[i]=='0')cnt1b++;
            else c1b.push_back(i/2);
        }
        if(cnt0a!=cnt0b||cnt1a!=cnt1b){
            cout<<-1<<'\n';
            continue;
        }
        long long sum = 0;
        for(int i =0; i<(int)c0a.size(); i++){
            sum+=abs(c0a[i]-c0b[i]);
        }
        for(int i =0; i<(int)c1a.size(); i++){
            sum+=abs(c1a[i]-c1b[i]);
        }
        cout<<sum<<'\n';

    }

    return 0;
}