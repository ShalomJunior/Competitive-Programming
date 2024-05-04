#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a)cin >> c;

    int L = 0, R = INF;
    for (int i = 0; i < n - 1; i++) {
        int sm = a[i] + a[i + 1];
        int LC = 0, RC = INF;

        if (a[i] < a[i + 1]) RC = sm / 2;

        if (a[i] > a[i + 1]) LC = sm / 2 + (sm & 1);

        L = max(L, LC);
        R = min(R, RC);
        if (L > R) { cout << -1 << endl; return; }
    }
    cout << L << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}