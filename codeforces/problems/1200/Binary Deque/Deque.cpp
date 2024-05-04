#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;
void solve() {
    int n, s; cin >> n >> s;
    int rem = 0;
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        rem += c;
    }

    unordered_map<int, int> suf;
    int curr = 0; suf[0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) suf[++curr] = n - i;
    }

    int ans = INF;
    for (int i = 0; i < n && rem >= s; i++) {
        ans = min(ans, i + suf[rem - s]);
        rem -= a[i];
    }
    cout << ((ans == INF) ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}