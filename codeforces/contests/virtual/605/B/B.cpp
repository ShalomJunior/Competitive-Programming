#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    map<char, int> cnt;
    for (auto& c : s) cnt[c]++;
    int x = min(cnt['L'], cnt['R']);
    int y = min(cnt['U'], cnt['D']);
    int t = min(x, y);
    if (x == 0 && y == 0) {
        cout << 0 << endl;
        cout << "" << endl;
        return;
    }
    else if (x == 0) {
        cout << 2 << endl;
        cout << (y ? "UD" : "") << endl;
        return;
    }
    else if (y == 0) {
        cout << 2 << endl;
        cout << (x ? "LR" : "") << endl;
        return;
    }
    string ans = "L";
    for (int i = 0; i < y; i++) ans += 'U';
    for (int i = 0; i < x; i++) ans += 'R';
    for (int i = 0; i < y; i++) ans += 'D';
    for (int i = 0; i < x - 1; i++) ans += 'L';
    cout << ans.size() << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}