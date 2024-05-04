#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(x + 1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[c]++;
    }
    for (int i = 1; i < x; i++) {
        a[i + 1] += a[i] / (i + 1);
        a[i] %= (i + 1);
    }
    a[x] = 0;
    int tot = count(a.begin(), a.end(), 0) - 1;
    cout << (tot == x ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}