#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>> k;
        string s;
        cin>>s;
        int size = s.size();
        int r = 0;
        int b= 0;
        for(int i =0; i<size; i++){
            int ind = (i-1+size)%size;
            if(s[i]=='1'){
                if(i&1)r++;
                else b++;
            }else if(s[ind]=='1'){
                if(ind&1){
                    r--;
                    b++;
                }else{
                    b--;
                    r++;
                }
            }
        }
        cout<<r<<" "<<b<<'\n';
    }

    return 0;
}