#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& c : p) cin >> c;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i + 1 < n; i++) {
            if (p[i] - 1 == p[i + 1]) {
                swap(p[i], p[i + 1]);
                flag = true;
            }
        }
    }
    cout << (is_sorted(p.begin(), p.end()) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}