#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int cnt = 0;
    vector<int> b(n);
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            b[i] = 1, cnt++;
        }
        else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            b[i] = -1, cnt++;
        }
    }
    for (int i = 1; i < n - 3; i++) {
        if (b[i] & b[i + 1] & b[i + 2]) {
            cout << cnt - 3 << endl;
            return;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        bool f = b[i] & b[i + 1];
        if (!f) continue;
        if ()
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}