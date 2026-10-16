#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        h[c]++;
    }
    vector<int> x;
    for (auto& [_, v] : h) x.push_back(v);
    sort(x.begin(), x.end());
    int m = x.size();
    int i = 0;
    while (i < m && k >= x[i]) k -= x[i++];
    cout << max(m - i, 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}