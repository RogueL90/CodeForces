#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int ans = x+y;
        int ops = 0;
        while((x^y)!=ans)
        for(int i = 29; i>=0; i--){
            int curr = ans>>i;
            int xc = x>>i;
            int yc = y>>i;
            if(curr&1){
                int cnt = 0;
                if(xc&1)cnt++;
                if(yc&1)cnt++;
                if(cnt==2){
                    int target1 = y & ((1 << (i + 1)) - 1);
                    int cnt1 = (1<<(i+1))-target1;
                    int target2 = y & ((1 << (i + 1)) - 1);
                    int cnt2 = (1<<(i))-target2;
                    if(cnt2<cnt1){
                        x-=cnt2;
                        y+=cnt2;
                        ops+=cnt2;
                    }else{
                        x-=cnt1;
                        y+=cnt1;
                        ops+=cnt1;
                    }
                }else if(cnt==1)continue;
                else{
                    int target1 = y & ((1 << (i + 1)) - 1);
                    int cnt1 = (1<<(i))-target1;
                    x-=cnt1;
                    y+=cnt1;
                    ops+=cnt1;
                }
            }else{
                if(xc&1){
                    int cnt =(x & ((1LL << i) - 1))+1;
                    x-=cnt;
                    y+=cnt;
                    ops+=cnt;
                }
                yc = y>>i;
                if(yc&1){
                    int target = y & ((1 << (i + 1)) - 1);
                    int cnt = (1<<(i+1))-target;
                    x-=cnt;
                    y+=cnt;
                    ops+=cnt;
                }
            }
        }
        cout<<ans<<" "<<ops<<'\n';
    }

    return 0;
}