#include <bits/stdc++.h>

using namespace std;

bool in(int v, int m) { return v >= 0 && v < m; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n);

    int bad = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (abs(p[i] - 1 - i) % k)bad++;
    }
    if (!bad) {
        cout << 0 << endl;
    }
    else { cout << ((bad == 2) ? 1 : -1) << endl; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}