#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    map<int, int> h;
    for (auto& c : x) {
        cin >> c;
        h[c]++;
    }
    int cnt = 0;
    for (int i = 0; i < 2 * n && i <= k - i; i++) {
        int l = i;
        int r = k - i;
        int mn = min(h[l], h[r]);
        if (l == r) {
            cnt += mn / 2;
        }
        else {
            cnt += mn;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
