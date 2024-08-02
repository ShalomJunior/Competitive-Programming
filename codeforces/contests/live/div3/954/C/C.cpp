#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> ids(m);
    for (auto& c : ids) cin >> c;
    string c; cin >> c;
    map<int, int> cnt;
    for (auto& p : ids) cnt[p - 1]++;
    deque<char> dq(c.begin(), c.end());
    sort(dq.begin(), dq.end());
    for (auto& [k, v] : cnt) {
        while (v > 1) {
            s[k] = dq.back();
            dq.pop_back();
            v--;
        }
        s[k] = dq[0];
        dq.pop_front();
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
