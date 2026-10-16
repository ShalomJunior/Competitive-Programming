#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    deque<char> a, b;
    for (auto& c : s) {
        int d = c - '0';
        d & 1 ? a.push_back(c) : b.push_back(c);
    }
    string ans;
    while (!a.empty() && !b.empty()) {
        if (a.front() < b.front()) {
            ans += a.front();
            a.pop_front();
        }
        else {
            ans += b.front();
            b.pop_front();
        }
    }
    while (!a.empty()) {
        ans += a.front();
        a.pop_front();
    }
    while (!b.empty()) {
        ans += b.front();
        b.pop_front();
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
