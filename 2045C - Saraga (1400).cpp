#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    string T;
    cin>>S>>T;
    vector<int> s(26, 400001);
    int n = (int)S.size();
    int m = (int)T.size();
    for(int i =1; i<n; i++){
        if(s[S[i]-'a']==400001)
        s[S[i]-'a']=i;
    }
    int pre1 = 400001;
    int suf1 = 400001;
    for(int i = m-2; i>=0; i--){
        if(m-i+s[T[i]-'a']<pre1+suf1){
            pre1 = s[T[i]-'a'];
            suf1 = m-i;
        }
    }
    string ans;
        if(pre1+suf1>=400001)ans = "-1"; else
        ans = S.substr(0, pre1)+T.substr(m-suf1);
    cout<<ans;

    return 0;
}