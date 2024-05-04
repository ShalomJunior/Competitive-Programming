#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    set<int> s(a.begin(), a.end());
    int m = s.size();
    if (m == 1) {
        cout << "YES" << endl;
        return;
    }
    if (m > 2) {
        cout << "NO" << endl;
        return;
    }
    int x = count(a.begin(), a.end(), *s.begin());
    int y = n - x;
    cout << (abs(x - y) <= 1 ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}