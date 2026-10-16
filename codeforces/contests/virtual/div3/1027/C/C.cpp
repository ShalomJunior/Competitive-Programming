#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int i = 1;
    int j = n - 2;
    while (i < j) {
        if (a[i] == a[i - 1])
            swap(a[i], a[n - 1 - i]);
        i++, j--;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}