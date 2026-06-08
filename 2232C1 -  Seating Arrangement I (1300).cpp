#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int cnt (int verts, string& str, int t, int s){
    int sA = 0;
    int cnt = 0;
    for(char curr : str){
        switch(curr) {
            case 'A' :
                if(verts && t){
                    verts--;
                    t--;
                    sA+=s-1;
                } else if(!sA){
                    cnt++;
                } else{
                    sA--;
                }
                break;
            case 'I' : 
                if(!t){
                    cnt++;
                }else{
                    t--;
                    sA+=s-1;
                }
                break;
            default :
                if(!sA){
                    cnt++;
                }else{
                    sA--;
                }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while(cases--){
        int n, t, s;
        cin >> n >> t >> s;
        string str;
        cin >> str;
        int ans = n- cnt(0, str, t, s);
        int verts = 0;
        for(int i = 0; i<n; i++){
            if(str[i] == 'A'){
                verts++;
                ans = max(ans, n- cnt(verts, str, t, s));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}