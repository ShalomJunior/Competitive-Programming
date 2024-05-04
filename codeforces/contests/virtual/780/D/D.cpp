#include <bits/stdc++.h>
using namespace std;

const int N = 5;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> z(n);
    int x = n;
    for (int i = n - 1; i >= 0; i--) {
        z[i] = x;
        if (a[i] == 0) x = i;
    }
    vector<int> neg(n + 1);
    x = -1;
    for (int i = 0; i <= n; i++) {
        neg[i] = x;
        if (i < n && a[i] < 0) x = i;
    }
    vector<vector<int>> cnt(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        if (i) cnt[i] = cnt[i - 1];
        cnt[i][a[i] + 2]++;
    }
    int L = n, R = n - 1;
    vector<int> best(5);
    best[3] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        vector<int> t = cnt[z[i] - 1];
        for (int j = 0; j < N; j++) {
            t[j] -= (i ? cnt[i - 1][j] : 0);
        }
        int s = t[0] + t[1];
        if (s % 2 == 0) {
            if (t[0] + t[N - 1] > best[0] + best[N - 1]) {
                best = t;
                L = i, R = z[i] - 1;
            }
            continue;
        }
        int pos = neg[z[i]] - 1;
        if (s > 1 || pos >= i) {
            t = cnt[pos];
            for (int j = 0; j < N; j++) {
                t[j] -= (i ? cnt[i - 1][j] : 0);
            }
            if (t[0] + t[N - 1] > best[0] + best[N - 1]) {
                best = t;
                L = i, R = pos;
            }
            continue;
        }
    }
    cout << L << " " << n - 1 - R << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}