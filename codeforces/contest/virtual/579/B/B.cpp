#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(4 * n);
    map<int, int> h;
    for (auto& c : a) {
        cin >> c;
        h[c]++;
    }
    for (auto& [k, cnt] : h) {
        if (cnt & 1) {
            cout << "NO" << endl;
            return;
        }
    }
    set<int> s;
    for (int i = 0; i < 4 * n; i++) {
        s.insert(a[0] * a[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        bool b = true;
        int area = *it;
        for (auto& [x, cnt] : h) {
            int y = area / x;
            if (x * y != area) {
                b = false;
                break;
            }
            if (x != y) {
                if (!h.count(y) || h.count(y) && h[x] != h[y]) {
                    b = false;
                    break;
                }
            }
            else {
                if (h[x] % 4) {
                    b = false;
                    break;
                }
            }
        }
        if (b) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}