#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> h;
    for (auto& c : s) h[c]++;
    set<pair<int, char>> p;
    for (auto& [ch, cnt] : h) p.insert({ cnt , ch });
    while (p.size() > 1) {
        auto mx = *prev(p.end());
        auto mn = *p.begin();
        p.erase(p.begin());
        p.erase(prev(p.end()));
        cout << mx.second << mn.second;
        if (--mn.first) p.insert(mn);
        if (--mx.first) p.insert(mx);
    }
    if (!p.empty()) {
        auto [cnt, ch] = *p.begin();
        for (int i = 0; i < cnt; i++) cout << ch;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
