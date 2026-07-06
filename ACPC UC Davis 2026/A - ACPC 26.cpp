#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
 
int solve(int n, vector<string> n_strings, int m, vector<string> m_strings) {
    set<string> s = {};
    for(string& str : m_strings){
        s.insert(str);
    }
    int count = 0;
    for(string& str : n_strings){
        str[0] = 'G';
        if(s.find(str) != s.end()){
            count++;
            s.erase(str);
        }
    }
    return count;
}
 
int main() {
    int n; cin >> n;
    vector<string> n_strings;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        n_strings.push_back(s);
    }
    int m; cin >> m;
    vector<string> m_strings;
    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        m_strings.push_back(s);
    }
    cout << solve(n, n_strings, m, m_strings) << endl;
}