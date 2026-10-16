#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> r;
    for (int i = 0; i < n; i++) r.insert(i + 1);
    vector<int> a(n);
    for (auto& c : a) {
        cin >> c;
        r.erase(c);
    }
    if (r.empty()) {
        for (int i = 0; i < k; i++) cout << a[i] << " ";
    }
    else if (r.size() == 1) {
        vector<int> p = { *r.begin() };
        for (int j = n - 2; j >= 0; j--) {
            if (a[j] != a.back()) {
                p.push_back(a[j]);
                break;
            }
        }
        p.push_back(a.back());
        for (int i = 0; i < k; i++) {
            cout << p[i % 3] << " ";
        }
    }
    else {
        vector<int> p = { *r.begin(), *prev(r.end()), a.back() };
        for (int i = 0; i < k; i++) cout << p[i % 3] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}
