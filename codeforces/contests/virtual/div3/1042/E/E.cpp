#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> b(n);
    for (auto& c : b) cin >> c;
    if (a.back() != b.back()) {
        cout << "NO" << endl;
        return;
    }
    vector<set<int>> s(n);
    for (int i = n - 1; i >= 0; i--) {
        s[i].insert(a[i]);
        if (a[i] != b[i]) {
            int need = a[i] ^ b[i];
            if (!s[i + 1].count(need)) {
                cout << "NO" << endl;
                return;
            }
            a[i] = b[i];
            s[i].insert(a[i]);
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