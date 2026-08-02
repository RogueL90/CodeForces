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
        multiset<int> multi;
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            multi.insert(x);
        }
        int l = 0;
        int r = n;
        int last = -1;
        while(l<=r){
            multiset<int> ms = multi;
            int mid = l+ (r-l)/2;
            bool done = true;
            for(int i =mid-1;i>=0; i--){
                auto it = ms.find(i);
                auto it1 = ms.lower_bound(2*i+1);
                if(it!=ms.end()){
                    ms.erase(it);
                }else if(it1!=ms.end()){
                    ms.erase(it1);
                }else{
                    done = false;
                    break;
                }
            }
            if(done){
                last= mid;
                l = mid+1;
            }else r = mid-1;
        }
        cout<<last<<'\n';
    }

    return 0;
}