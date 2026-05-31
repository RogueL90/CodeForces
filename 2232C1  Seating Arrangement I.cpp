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
     cin>> count;
     while(count--){
        int n, x, s;
        cin >> n >> x >> s;
        string str;
        cin >> str;
        int intr = x;
        int extr = 0;
        int seated = 0;
        int intrAmbi = 0;
        int Ava = 0;
        for(char ch : str){
            switch (ch){
                case 'I':
                    if(intr - intrAmbi> 0){
                        intr--;
                        extr+=s-1;
                        seated++;
                    }else if(Ava > 0 && extr >s-1){
                        extr--;
                        
                    }
                    break;
                case 'E':
                    if(extr > 0){
                        extr--;
                        seated++;
                    }  
                    break;
                default:
                    if(intr>0){
                        intrAmbi++;
                        Ava++;
                        seated++;
                    }
                    break;
            }
        }
        cout << seated << '\n';
     }

    return 0;
}