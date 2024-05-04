#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto& c : a)cin >> c;
    for (auto& c : b)cin >> c;

    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        mp1[a[i]] = i;
        mp2[b[i]] = i;
    }

    int pos = -1;
    vector<bool> open(n);
    for (int i = 0; i < n; i++) {
        int x = b[i];
        if (mp1[x] > mp2[x]) {
            open[i] = true;
            pos = i;
        }
    }

    if (pos == -1) { cout << 0 << endl; return; }

    for (int i = pos + 1; i < n - 1; i++) {
        int x = b[i], y = b[i + 1];
        if (mp1[x] > mp1[y] && mp2[x] < mp2[y]) {
            open[i] = true;
            pos = i;
        }
    }
    cout << pos + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}