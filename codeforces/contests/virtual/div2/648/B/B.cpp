#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;
    int x = count(b.begin(), b.end(), 0);
    int y = count(b.begin(), b.end(), 1);
    if (x && y) {
        cout << "YES" << endl;
    }
    else {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}