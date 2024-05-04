#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (x > y) {
        cout << n << endl;
    }
    else {
        int j = 0;
        while (j < n && a[j] <= x) j++;
        cout << (j + 1) / 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}