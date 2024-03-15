#include <bits/stdc++.h>
using namespace std;

vector<string> pat;
void solve() {
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i < pat.size(); i++) {
        if (s.find(pat[i]) == -1) {
            cout << pat[i] << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    function<void(int, string)> go = [&](int len, string t) {
        int z = t.length();
        if (z == len) {
            pat.push_back(t);
            return;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            go(len, t + c);
        }
        };
    for (int len = 1; len <= 4; len++) {
        go(len, "");
    }
    int t; cin >> t;
    while (t--)solve();
}