#include <bits/stdc++.h>
using namespace std;

const int N = 8;
void solve() {
    vector<string> vec(N);
    for (auto& s : vec) cin >> s;
    auto f = [&](string& s) {
        string ans;
        for (int i = 0; i < N; i++) {
            if (s[i] != '.') ans.push_back(s[i]);
        }
        return ans;
        };
    for (int j = 0; j < N; j++) {
        string s;
        for (int i = 0; i < N; i++) s += vec[i][j];
        s = f(s);
        if (!s.empty()) { cout << s << endl; return; }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}