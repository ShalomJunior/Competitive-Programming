#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    if (a[0] == 0) {
        cout << "NO" << endl;
        return;
    }
    int i = 0;
    while (i < n && a[i] != 0) i++;
    if (i >= n - 1) {
        cout << "NO" << endl;
        return;
    }
    int k = i;
    while (k < n&& a[k] != 1) k++;
    set<int> s;
    for (int j = n - 1; j > i; j--) {
        if (a[j] == 2) {
            if (!s.count(0) || !s.count(1)) {
                cout << "NO" << endl;
                return;
            }
            else {
                cout << (k < j ? "NO" : "YES") << endl;
                return;
            }
        }
        s.insert(a[j]);
    }
    if (s.count(0) && s.count(1)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}