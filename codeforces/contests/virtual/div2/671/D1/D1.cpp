#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    vector<int> p;
    for (int i = 1; i <= n; i += 2) {
        if (i + 1 <= n) p.push_back(i + 1);
        p.push_back(i);
    }
    cout << (n - 1) / 2 << endl;
    for (auto& c : p) {
        cout << a[c - 1] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
