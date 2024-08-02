#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end(), [&](int a, int b) {
        if ((a ^ b) >= 4) return true;
        return a < b;
        });
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}