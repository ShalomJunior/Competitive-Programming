#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c, h[c]++;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (auto& [k, v] : h) {
        for (int i = 0; i < v - 1; i++)
            a.push_back(k);
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