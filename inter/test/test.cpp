#include <bits/stdc++.h>
using namespace std;

set<int> get(string s) {

}

void solve(vector<string>& s) {
    int n = s.size();
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        set<int> let(s[i].begin(), s[i].end());
        string t;
        for (auto it = s.begin(); it != s.end(); it++) {
            t += *it;
        }
        s[i] = t;
    }
}

int main() {

}