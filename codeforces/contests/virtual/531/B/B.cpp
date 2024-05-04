#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    map<string, int> h;
    int M = 0;
    for (int i = 0; i < n - 1; i++) {
        M = max(M, ++h[s.substr(i, 2)]);
    }
    for (auto& [k, v] : h) {
        if (v == M) { cout << k << endl; return; }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}