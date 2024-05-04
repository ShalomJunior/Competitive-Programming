#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    unordered_set<int> s(a.begin(), a.end());
    bool flag = true;
    while (flag) {
        int m = a.size();
        if (m > 300) {
            cout << "NO" << endl;
            return;
        }
        flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int add = abs(a[i] - a[j]);
                if (!s.count(add)) {
                    flag = true;
                    a.push_back(add);
                    s.insert(add);
                }
            }
        }
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for (auto& c : a) cout << c << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)solve();
}