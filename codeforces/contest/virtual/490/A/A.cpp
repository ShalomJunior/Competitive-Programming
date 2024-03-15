#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    deque<int> dq(n);
    for (auto& c : dq) cin >> c;
    int ans = 0;
    while (!dq.empty() && dq.front() <= k) { ans++, dq.pop_front(); }
    while (!dq.empty() && dq.back() <= k) { ans++, dq.pop_back(); }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}