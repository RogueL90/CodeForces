#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;
    x--;
    string hate = " that I hate";
    string love = " that I love";
    string addon = "";
    for(int i =0; i<x;i++){
        addon += i%2 == 0 ? love : hate;
    }
    cout << "I hate" << addon << " it";

    return 0;
}