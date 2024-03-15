#include <bits/stdc++.h>
using namespace std;

const int N = 32;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(N);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        for (int j = 0; j < N; j++) {
            if (c & (1 << j)) a[j]++;
        }
    }
    vector<vector<int>> b(N, vector<int>());
    for (int i = 0; i < m; i++) {
        int c; c >> c;
        for (int j = N - 1; j >= 0; j--) {
            if (c & (1 << j)) {
                b[j].push_back(c);
                break;
            }
        }
    }
    int h = 0;
    for (int j = 0; j < N; j++) {
        if (a[j] & 1) h |= 1 << j;
    }
    int mn = h, mx = h;
    for (int i = N - 1; i >= 0; i--) {
        if (!(mn & (1 << i)) || (n & 1)) continue;
        int p = mn;
        for (auto& c : b[i]) p = min(p, mn ^ c);
        mn = p;
    }
    for (int i = N - 1; i >= 0; i--) {
        if (mx & (1 << i) || (n % 2 == 0)) continue;
        int p = mx & (1 << i);
        for (auto& c : b[i]) {
            for (int j = )
        }
        mx = p;
    }
    cout << mn << " " << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}