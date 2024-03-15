#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (auto& c : x)cin >> c;
    for (auto& c : y)cin >> c;

    priority_queue<int> neg, pos;
    for (int i = 0; i < n; i++) {
        int delta = y[i] - x[i];
        if (delta < 0) neg.push(-delta);
        else pos.push(delta);
    }

    int ans = 0;
    while (!neg.empty() && !pos.empty()) {
        int t = neg.top(); neg.pop();
        if (t <= pos.top()) {
            ans++;
            pos.pop();
        }
    }

    ans += (int)pos.size() / 2;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}