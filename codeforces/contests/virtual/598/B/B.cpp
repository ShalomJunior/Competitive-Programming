#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    int last = 0;
    while (last != n - 1) {
        int m = last;
        for (int i = last; i < n; i++) {
            if (a[i] < a[m]) m = i;
        }
        for (int i = m - 1; i >= last; i--)
            swap(a[i], a[i + 1]);
        last = (m == last ? last + 1 : m);
    }
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}