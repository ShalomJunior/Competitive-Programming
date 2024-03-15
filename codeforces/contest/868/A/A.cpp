#include <bits/stdc++.h>

using namespace std;

int f(int n) { return (n) ? n * (n - 1) : 0; }

void solve() {
    int t, k; cin >> t >> k;

    int p = 0, n = t;
    bool b = false;
    for (int i = 0; i < t; i++) {
        if (f(p) / 2 + f(n) / 2 == k) {
            b = true;
            break;
        }
        p++; n--;
    }
    if (!b) { cout << "NO" << endl; return; }
    vector<int> v;

    for (int i = 0; i < p; i++)v.push_back(1);
    for (int i = 0; i < n; i++)v.push_back(-1);

    cout << "YES" << endl;
    for (auto& c : v)cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}