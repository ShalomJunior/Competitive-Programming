#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(a.begin(), a.end());
    if (a[2] < 0 || a[n - 3] > 0) {
        cout << "NO" << endl;
        return;
    }
    map<int, int > h;
    vector<int> b;
    for (auto& c : a) {
        if (h[c] < 3)b.push_back(c);
        h[c]++;
    }
    int m = b.size();
    set<int> s(b.begin(), b.end());
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (!s.count(b[i] + b[j] + b[k])) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}